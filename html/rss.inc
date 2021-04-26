	<item>
		<title>Polymorphic Catch Performance in C\#</title>
		<link>https://www.SwATips.com/articles/20210426.html</link>
		<pubDate>Mon, 26 Apr 2021 00:00:00 -0500</pubDate>
<description><![CDATA[

<p>Return to <a href="/">SwATips</a> | <a href="articles/20210426.pdf">pdf</a></p>


<div class="maketitle">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a href="#cite.0@swatips">1</a>]<br/>
Generated Monday 26<sup class="textsuperscript">th</sup> April, 2021</h2>
<div class="author"><span class="rm-lmr-12">Jon Hood</span></div><br/>
<div class="date"><span class="rm-lmr-12">Monday 26</span><sup class="textsuperscript"><span class="rm-lmr-9">th</span></sup><span class="rm-lmr-12"> April, 2021</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead"><span class="titlemark">1   </span> <a id="x1-10001"/>Polymorphic Catch Performance in C#</h3>


<!-- l. 1 -->
<p class="noindent">In a recent code review, one of our customers were marked for being sloppy with catch-all exceptions (CWE-396),
which is sometimes an indicator of poorly designed program flow. To fix this, the developers changed the catch
blocks to something like the one in Figure <a href="#x1-10051">1<!-- tex4ht:ref: fig:20170518:exception  --></a>.
</p>
   

<figure class="figure"> 

                                                                                         
                                                                                         
<a id="x1-10051"/>
                                                                                         
                                                                                         
<!-- l. 4 -->
<div id="listing-1" class="lstlisting"><span class="label"><a id="x1-1001r1"/>1</span><span class="ec-lmtk-10">try</span><span class="ec-lmtt-10"> </span><br/><span class="label"><a id="x1-1002r2"/>2</span><span class="ec-lmtt-10">{ DoSomethingWith("C:\\File.txt"); } </span><br/><span class="label"><a id="x1-1003r3"/>3</span><span class="ec-lmtk-10">catch</span><span class="ec-lmtt-10"> (Exception e) when (e </span><span class="ec-lmtk-10">is</span><span class="ec-lmtt-10"> FileNotFoundException) </span><br/><span class="label"><a id="x1-1004r4"/>4</span><span class="ec-lmtt-10">{ DoSomethingElse(e); }</span>
</div>
<figcaption class="caption"><span class="id">Figure 1:</span><span class="content">When-Conditioned Exception</span></figcaption><!-- tex4ht:label?: x1-10051  -->
                                                                                         
                                                                                         
   
</figure>


<!-- l. 14 -->
<p class="indent">   The intent of a “when” clause in an exception is for situations where the exception may have an error
code. For example, a SqlException may return different codes that can be used to differentiate their
catch blocks and clean up a failed state. So how does the code in Figure <a href="#x1-10051">1<!-- tex4ht:ref: fig:20170518:exception  --></a> differ from the code in
Figure <a href="#x1-10102">2<!-- tex4ht:ref: fig:20170518:exception2  --></a>?
</p>
   

<figure class="figure"> 

                                                                                         
                                                                                         
<a id="x1-10102"/>
                                                                                         
                                                                                         
<!-- l. 17 -->
<div id="listing-2" class="lstlisting"><span class="label"><a id="x1-1006r1"/>1</span><span class="ec-lmtk-10">try</span><span class="ec-lmtt-10"> </span><br/><span class="label"><a id="x1-1007r2"/>2</span><span class="ec-lmtt-10">{ DoSomethingWith("C:\\File.txt"); } </span><br/><span class="label"><a id="x1-1008r3"/>3</span><span class="ec-lmtk-10">catch</span><span class="ec-lmtt-10"> (FileNotFoundException e) </span><br/><span class="label"><a id="x1-1009r4"/>4</span><span class="ec-lmtt-10">{ DoSomethingElse(e); }</span>
</div>
<figcaption class="caption"><span class="id">Figure 2:</span><span class="content">Classically-Conditioned Exception</span></figcaption><!-- tex4ht:label?: x1-10102  -->
                                                                                         
                                                                                         
   
</figure>


<!-- l. 27 -->
<p class="indent">   While both blocks of code achieve the same result, the generated code to catch the exception in Figure <a href="#x1-10051">1<!-- tex4ht:ref: fig:20170518:exception  --></a> has
twelve times as many instructions to execute. The .NET Intermediate Language (IL) is very different between the
two implementations. The “when” clause creates what the IL defines as a filter block and instantiates a structure
similar to a truth stack. This additional structure and the extra operations on it reduce performance and add
unnecessary bloat to the software. The generated IL can be compared in Figures <a href="#x1-10253">3<!-- tex4ht:ref: fig:20170518:exceptionil  --></a> and <a href="#x1-10274">4<!-- tex4ht:ref: fig:20170518:exception2il  --></a>. The IL was created in
optimized Release mode.
</p>
   

<figure class="figure"> 

                                                                                         
                                                                                         
<a id="x1-10253"/>
                                                                                         
                                                                                         
<!-- l. 30 -->
<div id="listing-3" class="lstlisting"><span class="label"><a id="x1-1011r1"/>1</span><span class="ec-lmtt-10">filter { </span><br/><span class="label"><a id="x1-1012r2"/>2</span><span class="ec-lmtt-10">IL_000d:  isinst [System.Runtime]System.Exception </span><br/><span class="label"><a id="x1-1013r3"/>3</span><span class="ec-lmtt-10">IL_0012:  dup </span><br/><span class="label"><a id="x1-1014r4"/>4</span><span class="ec-lmtt-10">IL_0013:  brtrue.s IL_0019 </span><br/><span class="label"><a id="x1-1015r5"/>5</span><span class="ec-lmtt-10">IL_0015:  pop </span><br/><span class="label"><a id="x1-1016r6"/>6</span><span class="ec-lmtt-10">IL_0016:  ldc.i4.0 </span><br/><span class="label"><a id="x1-1017r7"/>7</span><span class="ec-lmtt-10">IL_0017:  br.s IL_0024 </span><br/><span class="label"><a id="x1-1018r8"/>8</span><span class="ec-lmtt-10">IL_0019:  isinst [System.Runtime]System.IO.FileNotFoundException </span><br/><span class="label"><a id="x1-1019r9"/>9</span><span class="ec-lmtt-10">IL_001e:  ldnull </span><br/><span class="label"><a id="x1-1020r10"/>10</span><span class="ec-lmtt-10">IL_001f:  cgt.un </span><br/><span class="label"><a id="x1-1021r11"/>11</span><span class="ec-lmtt-10">IL_0021:  ldc.i4.0 </span><br/><span class="label"><a id="x1-1022r12"/>12</span><span class="ec-lmtt-10">IL_0022:  cgt.un </span><br/><span class="label"><a id="x1-1023r13"/>13</span><span class="ec-lmtt-10">IL_0024:  endfilter </span><br/><span class="label"><a id="x1-1024r14"/>14</span><span class="ec-lmtt-10">}</span>
</div>
<figcaption class="caption"><span class="id">Figure 3:</span><span class="content">When-Conditioned Exception IL</span></figcaption><!-- tex4ht:label?: x1-10253  -->
                                                                                         
                                                                                         
   
</figure>


<figure class="figure"> 

                                                                                         
                                                                                         
<a id="x1-10274"/>
                                                                                         
                                                                                         
<!-- l. 51 -->
<div id="listing-4" class="lstlisting"><span class="label"><a id="x1-1026r1"/></span><span class="ec-lmtk-10">catch</span><span class="ec-lmtt-10"> </span><span class="ec-lmtk-10">class</span><span class="ec-lmtt-10"> [mscorlib]System.IO.FileNotFoundException</span>
</div>
<figcaption class="caption"><span class="id">Figure 4:</span><span class="content">Classically-Conditioned Exception IL</span></figcaption><!-- tex4ht:label?: x1-10274  -->
                                                                                         
                                                                                         
   
</figure>


<!-- l. 58 -->
<p class="indent">   This leads to another question: what’s the most optimal way to catch several types of exceptions? The most
optimal way is to catch the general exception, then use polymorphism to operate on it (code in Figure <a href="#x1-10375">5<!-- tex4ht:ref: fig:20170518:exceptionif  --></a>). The IL
code adds a single comparison for each conditional in an if statement and avoids the overhead incurred by the when
clause’s filter block. Note that most scanning tools and style checkers will identify Figure <a href="#x1-10375">5<!-- tex4ht:ref: fig:20170518:exceptionif  --></a> as a catch
for the generic exception, but this should be marked as a false positive if the handler appropriately
determines the failure scenarios for the appropriate exception types. The IL code for Figure <a href="#x1-10375">5<!-- tex4ht:ref: fig:20170518:exceptionif  --></a> up to the
first exception type is shown in Figure <a href="#x1-10406">6<!-- tex4ht:ref: fig:20170518:exceptionifil  --></a>. Please also realize that such minimal performance gains
should not be interpreted as a reason to violate a consistent standard already established in a code
base.
</p>
   

<figure class="figure"> 

                                                                                         
                                                                                         
<a id="x1-10375"/>
                                                                                         
                                                                                         
<!-- l. 61 -->
<div id="listing-5" class="lstlisting"><span class="label"><a id="x1-1028r1"/>1</span><span class="ec-lmtk-10">try</span><span class="ec-lmtt-10"> </span><br/><span class="label"><a id="x1-1029r2"/>2</span><span class="ec-lmtt-10">{ DoSomethingWith("C:\\File.txt"); } </span><br/><span class="label"><a id="x1-1030r3"/>3</span><span class="ec-lmtk-10">catch</span><span class="ec-lmtt-10"> (Exception e) </span><br/><span class="label"><a id="x1-1031r4"/>4</span><span class="ec-lmtt-10">{ </span><br/><span class="label"><a id="x1-1032r5"/>5</span><span class="ec-lmtt-10">       </span><span class="ec-lmtk-10">if</span><span class="ec-lmtt-10"> ((e </span><span class="ec-lmtk-10">is</span><span class="ec-lmtt-10"> FileNotFoundException) || (e </span><span class="ec-lmtk-10">is</span><span class="ec-lmtt-10"> SecurityException)) </span><br/><span class="label"><a id="x1-1033r6"/>6</span><span class="ec-lmtt-10">               DoSomethingElse(e); </span><br/><span class="label"><a id="x1-1034r7"/>7</span><span class="ec-lmtt-10">       </span><span class="ec-lmtk-10">else</span><span class="ec-lmtt-10"> </span><br/><span class="label"><a id="x1-1035r8"/>8</span><span class="ec-lmtt-10">               Log(e); </span><br/><span class="label"><a id="x1-1036r9"/>9</span><span class="ec-lmtt-10">}</span>
</div>
<figcaption class="caption"><span class="id">Figure 5:</span><span class="content">If-Formatted Exception Chain</span></figcaption><!-- tex4ht:label?: x1-10375  -->
                                                                                         
                                                                                         
   
</figure>


<figure class="figure"> 

                                                                                         
                                                                                         
<a id="x1-10406"/>
                                                                                         
                                                                                         
<!-- l. 77 -->
<div id="listing-6" class="lstlisting"><span class="label"><a id="x1-1038r1"/></span><span class="ec-lmtk-10">catch</span><span class="ec-lmtt-10"> </span><span class="ec-lmtk-10">class</span><span class="ec-lmtt-10"> [mscorlib]System.Exception { </span><br/><span class="label"><a id="x1-1039r2"/></span><span class="ec-lmtt-10">       IL_000d:  isinst [System.Runtime]System.IO.FileNotFoundException</span>
</div>
<figcaption class="caption"><span class="id">Figure 6:</span><span class="content">If-Formatted Exception Chain IL</span></figcaption><!-- tex4ht:label?: x1-10406  -->
                                                                                         
                                                                                         
   
</figure>


<!-- l. 85 -->
<p class="indent">   When performance is a primary concern, developers should include comments that indicate their consideration of
exceptional cases in generic catch blocks. Validators should watch for these comments to help them mark the generic
exception catches as false positives.
                                                                                         
                                                                                         
</p>
   

<h3 class="sectionHead"><a id="x1-20001"/>References</h3>


<!-- l. 49 -->
<p class="noindent">    
</p>


<dl class="thebibliography"><dt id="X0-swatips" class="thebibliography">
[1]  
</dt><dd id="bib-1" class="thebibliography">
<!-- l. 49 --><p class="noindent"><a id="cite.0@swatips"/>Jon Hood, ed. <span class="rm-lmri-10">SwATips</span>. <a class="url" href="https://www.SwATips.com/"><span class="ec-lmtt-10">https://www.SwATips.com/</span></a>.</p></dd></dl>

 

]]></description>
	</item>
	<item>
		<title>Heap Inspection</title>
		<link>https://www.SwATips.com/articles/20210419.html</link>
		<pubDate>Mon, 19 Apr 2021 00:00:00 -0500</pubDate>
<description><![CDATA[

<p>Return to <a href="/">SwATips</a> | <a href="articles/20210419.pdf">pdf</a></p>


<div class="maketitle">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a id="page.3"/><a href="article.html#X0-swatips">2</a>]<br/>
Generated Tuesday 20<sup class="textsuperscript">th</sup> April, 2021</h2>
<div class="author"><span class="rm-lmr-12">Andrew Perry</span></div><br/>
<div class="date"><span class="rm-lmr-12">Monday 19</span><sup class="textsuperscript"><span class="rm-lmr-9">th</span></sup><span class="rm-lmr-12"> April, 2021</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead"><span class="titlemark">1   </span> <a id="x1-10001"/>Heap Inspection</h3>


<!-- l. 1 -->
<p class="noindent">One of the first findings that I found when I began validating software assurance scans and something that intrigued
me to learn more about was <i>Heap Inspections</i>.[<a id="page.4"/><a href="article.html#X0-20210419-cwe-244">1</a>] In order to know how to resolve this issue, there are some things to
understand about how heap is used in RAM in order to see how this vulnerability plays out and ways to fix
it.
</p>
<!-- l. 3 -->
<p class="noindent">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.1   </span> <a id="x1-20001.1"/>What is Heap?</h4>


<!-- l. 5 -->
<p class="noindent">When we declare a variable in an application, it allocates some memory in RAM. A stack is an array of memory
that stores variables and implements a block allocation that is reserved in a LIFO (Last in, First out). When data
are written, the stack trends downwards towards the heap. The heap is a location in memory that a program can
use to store data in some various amount that may not be known until the program is running. Heap trends
upwards when data is passed whereas a stack trends in a downward direction. When creating an object string that
points to the stack memory, its value is stored in the heap. Heap is different than stack in that it is dynamically
stored in memory which means that it can be stored and removed in any order. If the heap has data that has
a fixed length memory block, it will overwrite expired or free values that were originally stored.[<a href="article.html#X0-20210419-guru99">5</a>,
<a href="article.html#X0-20210419-indika">3</a>]
</p>
<!-- l. 7 -->
<p class="noindent">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.2   </span> <a id="x1-30001.2"/>What is Heap Inspection?</h4>


<!-- l. 9 -->
<p class="noindent">In the case of a Heap Inspection, when information is stored in machine memory that is unencrypted and is using a
<span class="ec-lmtt-10">realloc() </span>function to increase the size of the block of allocated memory, an attacker can perform a memory dump
that could compromise the system. This can cause all kinds of problems such as crash the program, but it can also
expose sensitive information because it is not removed from memory properly. There are some ways to help mitigate
this issue in C# or .NET applications.
</p>
<!-- l. 11 -->
<p class="noindent">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.3   </span> <a id="x1-40001.3"/>Heap Inspection Prevention</h4>


<!-- l. 13 -->
<p class="noindent">Using the <span class="ec-lmtt-10">String </span>object should not be used if the information contains sensitive information such as a password,
credit card number, etc. It is important to not allow plain text passwords; hash them with a crytographically secure
hasing algorithm. An important note is to invoke a Disposable method to use as a garbage collector to
free computer memory when an object is no longer needed. One of the ways you can avoid a heap
inspection and to protect sensitive data is by using a <span class="ec-lmtt-10">SecureString</span>. Consider the code in Listing <a href="#x1-4001r1">1<!-- tex4ht:ref: fig:20210419:1  --></a>.[<a href="article.html#X0-20210419-codeproject">6</a>,
<a href="article.html#X0-20210419-swain">4</a>]
</p>
   

<!-- l. 15 -->


<p><a id="x1-4001r1"/></p>


<p><a id="x1-4002"/></p>
   

<div class="lstlisting" id="listing-1"><span class="label"><a id="x1-4003r1"/></span><span class="ec-lmtt-9">SecureString securePwd = </span><span class="ec-lmtk-10x-x-90">new</span><span class="ec-lmtt-9"> SecureString(); </span><br/><span class="label"><a id="x1-4004r2"/></span><span class="ec-lmtt-9">ConsoleKeyInfo key; </span><br/><span class="label"><a id="x1-4005r3"/></span><span class="ec-lmtt-9">Console.Write("Enter password: "); </span><br/><span class="label"><a id="x1-4006r4"/></span><span class="ec-lmtk-10x-x-90">do</span><span class="ec-lmtt-9"> { </span><br/><span class="label"><a id="x1-4007r5"/></span><span class="ec-lmtt-9">        key = Console.ReadKey(</span><span class="ec-lmtk-10x-x-90">true</span><span class="ec-lmtt-9">);…</span>
<figcaption class="caption"><span class="id">Listing 1:</span><span class="content">SecureString Example</span></figcaption><!-- tex4ht:label?: x1-4001r1  -->
   
</div>

                                                                                         
                                                                                         

<!-- l. 24 -->
<p class="noindent">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.4   </span> <a id="x1-50001.4"/>Conclusion</h4>


<!-- l. 26 -->
<p class="noindent">In conclusion, avoiding this issue can be a challenge, if not impossible. However, it’s important that if this finding
has been found in a static analysis scan, it should not be marked as a false positive, particularly if the code
could ever be placed in a shared environment. Doing so may allow the code to go unnoticed while
it continues to have unintended results and could allow sensitive information to be obtained by an
adversary.
                                                                                         
                                                                                         
</p>
   

<h3 class="sectionHead"><a id="x1-60001.4"/>References</h3>


<!-- l. 49 -->
<p class="noindent">    
</p>


<dl class="thebibliography"><dt id="X0-20210419-cwe-244" class="thebibliography">
[1]  
</dt><dd id="bib-1" class="thebibliography">
<!-- l. 49 --><p class="noindent"><a id="page.6"/><a id="X0-" href="article.html"/>CWE  Content  Team.  “CWE-244:  Improper  Clearing  of  Heap  Memory  Before  Release  (’Heap
Inspection’)”. In: (2020). <span class="small-caps">url</span>: <a class="url" href="https://cwe.mitre.org/data/definitions/244.html"><span class="ec-lmtt-10">https://cwe.mitre.org/data/definitions/244.html</span></a>.
</p>    
</dd>
<dt id="X0-swatips" class="thebibliography">
[2]  
</dt><dd id="bib-2" class="thebibliography">
<!-- l. 49 --><p class="noindent">Jon Hood, ed. <span class="rm-lmri-10">SwATips</span>. <a class="url" href="https://www.SwATips.com/"><span class="ec-lmtt-10">https://www.SwATips.com/</span></a>.
</p>    
</dd>
<dt id="X0-20210419-indika" class="thebibliography">
[3]  
</dt><dd id="bib-3" class="thebibliography">
<!-- l. 49 --><p class="noindent">Indika.        “Difference        Between        Stack        and        Heap”.        In:        (2011).        <span class="small-caps">url</span>:
<a class="url" href="https://www.differencebetween.com/difference-between-stack-and-vs-heap/"><span class="ec-lmtt-10">https://www.differencebetween.com/difference-between-stack-and-vs-heap/</span></a>.
</p>    
</dd>
<dt id="X0-20210419-swain" class="thebibliography">
[4]  
</dt><dd id="bib-4" class="thebibliography">
<!-- l. 49 --><p class="noindent">Chittaranjan Swain. “How to fix heap inspection vulnerability in c#”. In: (2019). <span class="small-caps">url</span>: <a class="url" href="https://www.c-sharpcorner.com/forums/how-to-fix-heap-inspection-vulnerability-in-c-sharp"><span class="ec-lmtt-10">https://www.c-sharpcorner.com/forums/how-to-fix-heap-inspection-vulnerability-in-c-sharp</span></a>.
</p>    
</dd>
<dt id="X0-20210419-guru99" class="thebibliography">
[5]  
</dt><dd id="bib-5" class="thebibliography">
<!-- l. 49 --><p class="noindent">Unknown.       “Stack       vs       Heap:       Know       the       Difference”.       In:       ().       <span class="small-caps">url</span>:
<a class="url" href="https://www.guru99.com/stack-vs-heap.html"><span class="ec-lmtt-10">https://www.guru99.com/stack-vs-heap.html</span></a>.
</p>    
</dd>
<dt id="X0-20210419-codeproject" class="thebibliography">
[6]  
</dt><dd id="bib-6" class="thebibliography">
<!-- l. 49 --><p class="noindent">Unknown. “To Avoid Heap Inspection”. In: (2015). <span class="small-caps">url</span>: <a class="url" href="https://www.codeproject.com/Questions/1039781/To-Avoid-Heap-Inspection-I-Used-Securestring-Inste"><span class="ec-lmtt-10">https://www.codeproject.com/Questions/1039781/To-Avoid-Heap-Inspection-I-Used-Securestring-Inste</span></a>.</p></dd></dl>

 

]]></description>
	</item>
	<item>
		<title>Sticking with a RAII Standard</title>
		<link>https://www.SwATips.com/articles/20210412.html</link>
		<pubDate>Mon, 12 Apr 2021 00:00:00 -0500</pubDate>
<description><![CDATA[

<p>Return to <a href="/">SwATips</a> | <a href="articles/20210412.pdf">pdf</a></p>


<div class="maketitle">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a id="page.3"/><a href="article.html#X0-swatips">1</a>]<br/>
Generated Tuesday 20<sup class="textsuperscript">th</sup> April, 2021</h2>
<div class="author"><span class="rm-lmr-12">Jon Hood</span></div><br/>
<div class="date"><span class="rm-lmr-12">Monday 12</span><sup class="textsuperscript"><span class="rm-lmr-9">th</span></sup><span class="rm-lmr-12"> April, 2021</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead"><span class="titlemark">1   </span> <a id="x1-10001"/>Sticking with a RAII Standard</h3>


<!-- l. 1 -->
<p class="noindent">Resource Acquisition Is Initialization (RAII). When working with legacy code, often variables and memory
management do not use RAII concepts. When memory is created in an uninitialized state, developers risk the use of
uninitialized memory further down in the application data flow.
</p>
<!-- l. 3 -->
<p class="indent">   To solve this, C++ implemented two ways of initializing new memory: <i>default</i> initialization and <i>value</i>
initialization. While default initialization is typically faster, developers quickly realized that there was rarely a
reason to keep memory uninitialized. Initializing memory as soon as it’s allocated keeps developers from shooting
themselves in the foot.
</p>
<!-- l. 5 -->
<p class="indent">   One of the best ways to prevent memory errors is to use RAII. Particularly in exception-based code, RAII
concepts provide a memory-safe technique for resource management.[<a id="page.4"/><a href="article.html#X0-20210412-stroustrup2001">2</a>] Several issues face developers when
maintaining legacy code with new programming concepts, particularly in the DoD. Legacy code is
generally void of RAII concepts and has not been built with the latest standards of safe programming
practices.
</p>
<!-- l. 7 -->
<p class="noindent">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.1   </span> <a id="x1-20001.1"/>Updating the Code</h4>


<!-- l. 9 -->
<p class="noindent">The first option for maintaining legacy code in a memory-safe way is to update the code. Wrapping old pointers in
smart pointers can help make the code more maintainable.
</p>
   

<!-- l. 11 -->


<p><a id="x1-2001r1"/></p>


<p><a id="x1-2002"/></p>
   

<div id="listing-1" class="lstlisting"><span class="label"><a id="x1-2003r1"/></span><span class="ec-lmtt-9">bool *newBool = new bool(); </span><br/><span class="label"><a id="x1-2004r2"/></span><span class="ec-lmtk-10x-x-90">if</span><span class="ec-lmtt-9"> (*newBool) </span><br/><span class="label"><a id="x1-2005r3"/></span><span class="ec-lmtt-9">        cout &lt;&lt; "We</span><span class="ts1-lmtt9-">'</span><span class="ec-lmtt-9">re␣true!"␣&lt;&lt;␣endl; </span><br/><span class="label"><a id="x1-2006r4"/></span><span class="ec-lmtt-9">else </span><br/><span class="label"><a id="x1-2007r5"/></span><span class="ec-lmtt-9">␣␣␣␣␣␣␣␣cout␣&lt;&lt;␣"We</span><span class="ts1-lmtt9-">'</span><span class="ec-lmtt-9">re false!" &lt;&lt; endl; </span><br/><span class="label"><a id="x1-2008r6"/></span><span class="ec-lmtt-9">delete newBool;</span>
<figcaption class="caption"><span class="id">Listing 1:</span><span class="content">Non-compliant listing</span></figcaption><!-- tex4ht:label?: x1-2001r1  -->
   
</div>


<!-- l. 20 -->


<p><a id="x1-2009r2"/></p>


<p><a id="x1-2010"/></p>
   

<div id="listing-2" class="lstlisting"><span class="label"><a id="x1-2011r1"/></span><span class="ec-lmtk-10x-x-90">auto</span><span class="ec-lmtt-9"> newBool = make_shared&lt;bool&gt;(); </span><br/><span class="label"><a id="x1-2012r2"/></span><span class="ec-lmtti-10x-x-90">//Another way: shared_ptr&lt;bool&gt; newBool(new bool());</span><span class="ec-lmtt-9"> </span><br/><span class="label"><a id="x1-2013r3"/></span><span class="ec-lmtk-10x-x-90">if</span><span class="ec-lmtt-9"> (*newBool) </span><br/><span class="label"><a id="x1-2014r4"/></span><span class="ec-lmtt-9">        cout &lt;&lt; "We</span><span class="ts1-lmtt9-">'</span><span class="ec-lmtt-9">re␣true!"␣&lt;&lt;␣endl; </span><br/><span class="label"><a id="x1-2015r5"/></span><span class="ec-lmtt-9">else </span><br/><span class="label"><a id="x1-2016r6"/></span><span class="ec-lmtt-9">␣␣␣␣␣␣␣␣cout␣&lt;&lt;␣"We</span><span class="ts1-lmtt9-">'</span><span class="ec-lmtt-9">re false!" &lt;&lt; endl;</span>
<figcaption class="caption"><span class="id">Listing 2:</span><span class="content">RAII-compliant listing</span></figcaption><!-- tex4ht:label?: x1-2009r1  -->
   
</div>


<!-- l. 29 -->
<p class="indent">   There are several issues with updating the old code to the RAII-compliant code:
</p>
     

<ol class="enumerate1">
<li id="x1-2018x1" class="enumerate">     
Forgetting to remove the manual memory management can cause double-free errors.
</li>     
<li id="x1-2020x2" class="enumerate">
Updating the code can cause translation issues (eg: between default and value initialization)
</li>     
<li id="x1-2022x3" class="enumerate">
Inconsistency can increase maintenance burdens for maintained code.
</li>     
<li id="x1-2024x4" class="enumerate">
Deletion of arrays require special handling.</li></ol>

                                                                                         
                                                                                         

<!-- l. 37 -->
<p class="noindent">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.2   </span> <a id="x1-30001.2"/>Double Frees</h4>


<!-- l. 39 -->
<p class="noindent">Developers can introduce double free conditions where a pointer is managed by both a smart pointer and in the
code itself. Also, conditions arise when a single pointer is handed over to multiple smart pointers for
management.
</p>
<!-- l. 41 -->
<p class="indent">   At the time of this writing, the latest versions of Fortify, Coverity, Checkmarx, Parasoft, clang-analyzer, and the
GCC 10 <span class="ec-lmtt-10">-fanalyzer </span>flag are all incapable of identifying the double free in the following snippets:
</p>
   

<!-- l. 43 -->


<p><a id="x1-3001r3"/></p>


<p><a id="x1-3002"/></p>
   

<div id="listing-3" class="lstlisting"><span class="label"><a id="x1-3003r1"/></span><span class="ec-lmtt-9">bool *newBool = new bool(); </span><br/><span class="label"><a id="x1-3004r2"/></span><span class="ec-lmtt-9">shared_ptr&lt;bool&gt; test1 (newBool); </span><br/><span class="label"><a id="x1-3005r3"/></span><span class="ec-lmtt-9">shared_ptr&lt;bool&gt; test2 (newBool); </span><br/><span class="label"><a id="x1-3006r4"/></span><span class="ec-lmtti-10x-x-90">//...</span>
<figcaption class="caption"><span class="id">Listing 3:</span><span class="content">Double Smart Pointer</span></figcaption><!-- tex4ht:label?: x1-3001r1  -->
   
</div>


<!-- l. 50 -->


<p><a id="x1-3007r4"/></p>


<p><a id="x1-3008"/></p>
   

<div id="listing-4" class="lstlisting"><span class="label"><a id="x1-3009r1"/></span><span class="ec-lmtt-9">bool *newBool = new bool(); </span><br/><span class="label"><a id="x1-3010r2"/></span><span class="ec-lmtt-9">shared_ptr&lt;bool&gt; test1 (newBool); </span><br/><span class="label"><a id="x1-3011r3"/></span><span class="ec-lmtti-10x-x-90">//...</span><span class="ec-lmtt-9"> </span><br/><span class="label"><a id="x1-3012r4"/></span><span class="ec-lmtt-9">delete newBool;</span>
<figcaption class="caption"><span class="id">Listing 4:</span><span class="content">Smart and Dumb Pointer</span></figcaption><!-- tex4ht:label?: x1-3007r1  -->
   
</div>


<!-- l. 57 -->
<p class="noindent">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.3   </span> <a id="x1-40001.3"/>Initialization Errors</h4>


<!-- l. 59 -->
<p class="noindent">We’ve also seen a large number of initialization errors when updating to smart pointers. Using the above examples,
it’s tempting for a developer to use shortcuts and do something like the following:
</p>
   

<!-- l. 61 -->


<p><a id="x1-4001r5"/></p>


<p><a id="x1-4002"/></p>
   

<div id="listing-5" class="lstlisting"><span class="label"><a id="x1-4003r1"/></span><span class="ec-lmtt-9">shared_ptr&lt;bool&gt; test1 (new bool); </span><br/><span class="label"><a id="x1-4004r2"/></span><span class="ec-lmtt-9">cout &lt;&lt; "Test1 is: " &lt;&lt; *test1 &lt;&lt; endl;</span>
<figcaption class="caption"><span class="id">Listing 5:</span><span class="content">Uninitialized Boolean</span></figcaption><!-- tex4ht:label?: x1-4001r1  -->
   
</div>


<!-- l. 66 -->
<p class="indent">   The unpredictable nature of this issue can be demonstrated in the following example where the Boolean uses
default initialization and obtains a random value from previously-freed memory.
</p>
   

<!-- l. 68 -->


<p><a id="x1-4005r6"/></p>


<p><a id="x1-4006"/></p>
   

<div id="listing-6" class="lstlisting"><span class="label"><a id="x1-4007r1"/></span><span class="ec-lmtk-10x-x-90">#include</span><span class="ec-lmtt-9"> &lt;climits&gt; </span><br/><span class="label"><a id="x1-4008r2"/></span><span class="ec-lmtk-10x-x-90">#include</span><span class="ec-lmtt-9"> &lt;iostream&gt; </span><br/><span class="label"><a id="x1-4009r3"/></span><span class="ec-lmtk-10x-x-90">#include</span><span class="ec-lmtt-9"> &lt;memory&gt; </span><br/><span class="label"><a id="x1-4010r4"/></span><span class="ec-lmtk-10x-x-90">#include</span><span class="ec-lmtt-9"> &lt;random&gt; </span><br/><span class="label"><a id="x1-4011r5"/></span><span class="ec-lmtt-9">using namespace std; </span><br/><span class="label"><a id="x1-4012r6"/></span><span class="ec-lmtk-10x-x-90">int</span><span class="ec-lmtt-9"> main() </span><br/><span class="label"><a id="x1-4013r7"/></span><span class="ec-lmtt-9">{ </span><br/><span class="label"><a id="x1-4014r8"/></span><span class="ec-lmtt-9">        random_device rd; </span><br/><span class="label"><a id="x1-4015r9"/></span><span class="ec-lmtt-9">        mt19937 gen(rd()); </span><br/><span class="label"><a id="x1-4016r10"/></span><span class="ec-lmtt-9">        uniform_int_distribution&lt;&gt; distrib(INT_MIN, INT_MAX); </span><br/><span class="label"><a id="x1-4017r11"/></span><span class="ec-lmtt-9">        vector&lt;</span><span class="ec-lmtk-10x-x-90">int</span><span class="ec-lmtt-9">*&gt; deleteLater; </span><br/><span class="label"><a id="x1-4018r12"/></span><span class="ec-lmtt-9">        </span><span class="ec-lmtk-10x-x-90">for</span><span class="ec-lmtt-9"> (</span><span class="ec-lmtk-10x-x-90">int</span><span class="ec-lmtt-9"> i = 0; i &lt; 100; i++) </span><br/><span class="label"><a id="x1-4019r13"/></span><span class="ec-lmtt-9">        { </span><br/><span class="label"><a id="x1-4020r14"/></span><span class="ec-lmtt-9">               </span><span class="ec-lmtk-10x-x-90">int</span><span class="ec-lmtt-9"> *deleteMe = new </span><span class="ec-lmtk-10x-x-90">int</span><span class="ec-lmtt-9">; </span><br/><span class="label"><a id="x1-4021r15"/></span><span class="ec-lmtt-9">               *deleteMe = distrib(gen); </span><br/><span class="label"><a id="x1-4022r16"/></span><span class="ec-lmtti-10x-x-90">               //delete some memory now</span><span class="ec-lmtt-9"> </span><br/><span class="label"><a id="x1-4023r17"/></span><span class="ec-lmtt-9">               </span><span class="ec-lmtk-10x-x-90">if</span><span class="ec-lmtt-9"> (*deleteMe &gt; 0) </span><br/><span class="label"><a id="x1-4024r18"/></span><span class="ec-lmtt-9">                       delete deleteMe; </span><br/><span class="label"><a id="x1-4025r19"/></span><span class="ec-lmtt-9">               </span><span class="ec-lmtk-10x-x-90">else</span><span class="ec-lmtt-9"> </span><br/><span class="label"><a id="x1-4026r20"/></span><span class="ec-lmtt-9">                       deleteLater.push_back(deleteMe); </span><br/><span class="label"><a id="x1-4027r21"/></span><span class="ec-lmtt-9">        } </span><br/><span class="label"><a id="x1-4028r22"/></span><span class="ec-lmtt-9">        shared_ptr&lt;bool&gt; newBool(new bool); </span><br/><span class="label"><a id="x1-4029r23"/></span><span class="ec-lmtt-9">        cout &lt;&lt; "Value: " &lt;&lt; *newBool &lt;&lt; endl; </span><br/><span class="label"><a id="x1-4030r24"/></span><span class="ec-lmtti-10x-x-90">        //delete some memory later</span><span class="ec-lmtt-9"> </span><br/><span class="label"><a id="x1-4031r25"/></span><span class="ec-lmtt-9">        </span><span class="ec-lmtk-10x-x-90">for</span><span class="ec-lmtt-9"> (</span><span class="ec-lmtk-10x-x-90">int</span><span class="ec-lmtt-9"> *n : deleteLater) </span><br/><span class="label"><a id="x1-4032r26"/></span><span class="ec-lmtt-9">               delete n; </span><br/><span class="label"><a id="x1-4033r27"/></span><span class="ec-lmtt-9">        </span><span class="ec-lmtk-10x-x-90">return</span><span class="ec-lmtt-9"> 0; </span><br/><span class="label"><a id="x1-4034r28"/></span><span class="ec-lmtt-9">}</span>
<figcaption class="caption"><span class="id">Listing 6:</span><span class="content">Uninitialized Boolean</span></figcaption><!-- tex4ht:label?: x1-4005r1  -->
   
</div>

                                                                                         
                                                                                         

<!-- l. 99 -->
<p class="noindent">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.4   </span> <a id="x1-50001.4"/>Inconsistency Can Increase Maintenance Costs</h4>


<!-- l. 101 -->
<p class="noindent">Consider updated code that uses a multitude of different memory handling methods. Some memory is managed
manually using <span class="ec-lmtt-10">malloc </span>and <span class="ec-lmtt-10">free</span>. Some pass the previous pointer values to smart pointers for their management.
Others have been updated to use the <span class="ec-lmtt-10">make_shared </span>construct. Still others have been updated to custom classes and
structs.
</p>
<!-- l. 103 -->
<p class="indent">   Consistency is more important than updating. Introducing multiple memory handling patterns to a section of
code increases its complexity. If old memory handling methods cannot be replaced or are not planned to be replaced,
it may make more sense to stick with confusing (but consistent) code rather than adding additional
complexity.
</p>
<!-- l. 105 -->
<p class="noindent">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.5   </span> <a id="x1-60001.5"/>Smart Pointers and Arrays</h4>


<!-- l. 107 -->
<p class="noindent">Finally, some special considerations are needed for allowing smart pointers to handle arrays. The <span class="ec-lmtt-10">shared_ptr</span>
construct permits the developer to define a custom deleter like the one for this array of 10 Booleans:
</p>
   

<!-- l. 109 -->


<p><a id="x1-6001r7"/></p>


<p><a id="x1-6002"/></p>
   

<div id="listing-7" class="lstlisting"><span class="label"><a id="x1-6003r1"/></span><span class="ec-lmtt-9">shared_ptr&lt;bool&gt; test1{ </span><br/><span class="label"><a id="x1-6004r2"/></span><span class="ec-lmtt-9">        new bool[10], [](</span><span class="ec-lmtk-10x-x-90">const</span><span class="ec-lmtt-9"> bool *ptr) { delete [] ptr; } </span><br/><span class="label"><a id="x1-6005r3"/></span><span class="ec-lmtt-9">};</span>
<figcaption class="caption"><span class="id">Listing 7:</span><span class="content">Custom Deleter</span></figcaption><!-- tex4ht:label?: x1-6001r1  -->
   
</div>


<!-- l. 115 -->
<p class="noindent">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.6   </span> <a id="x1-70001.6"/>Conclusion</h4>


<!-- l. 117 -->
<p class="noindent">Smart pointers and RAII concepts help developers prevent memory errors that can plague software. Updating legacy
code to RAII concepts can increase its maintainability, usefulness, and security. Nevertheless, updates to the code
should not come at a price of inconsistency. When updates can only be applied partially or introduce additional
complexity, consistency should be preferred.
                                                                                         
                                                                                         
</p>
   

<h3 class="sectionHead"><a id="x1-80001.6"/>References</h3>


<!-- l. 49 -->
<p class="noindent">    
</p>


<dl class="thebibliography"><dt class="thebibliography" id="X0-swatips">
[1]  
</dt><dd class="thebibliography" id="bib-1">
<!-- l. 49 --><p class="noindent"><a id="page.7"/><a id="X0-" href="article.html"/>Jon Hood, ed. <span class="rm-lmri-10">SwATips</span>. <a class="url" href="https://www.SwATips.com/"><span class="ec-lmtt-10">https://www.SwATips.com/</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-20210412-stroustrup2001">
[2]  
</dt><dd class="thebibliography" id="bib-2">
<!-- l. 49 --><p class="noindent">Bjarne    Stroustrup.    “Exception    Safety:    Concepts    and    Techniques”.    In:    (2001).    <span class="small-caps">url</span>:
<a class="url" href="https://www.stroustrup.com/except.pdf"><span class="ec-lmtt-10">https://www.stroustrup.com/except.pdf</span></a>.</p></dd></dl>

 

]]></description>
	</item>
	<item>
		<title>COTS, GOTS, and NOTS software in RMF for the Army</title>
		<link>https://www.SwATips.com/articles/20210405.html</link>
		<pubDate>Mon, 05 Apr 2021 00:00:00 -0500</pubDate>
<description><![CDATA[

<p>Return to <a href="/">SwATips</a> | <a href="articles/20210405.pdf">pdf</a></p>


<div class="maketitle">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a href="#cite.0@swatips">2</a>]<br/>
Generated Monday 5<sup class="textsuperscript">th</sup> April, 2021</h2>
<div class="author"><span class="rm-lmr-12">Jon Hood</span></div><br/>
<div class="date"><span class="rm-lmr-12">Monday 5</span><sup class="textsuperscript"><span class="rm-lmr-9">th</span></sup><span class="rm-lmr-12"> April, 2021</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead"><span class="titlemark">1   </span> <a id="x1-10001"/>COTS, GOTS, and NOTS software in RMF for the Army</h3>


<!-- l. 1 -->
<p class="noindent">When working as a government contractor security professional for a system that includes custom software, three
different classes of software must be considered as part of the RMF process: </p>


<ul class="itemize1">     
<li class="itemize">COTS—Commercial Off-The-Shelf
</li>     
<li class="itemize">GOTS—Government Off-The-Shelf
</li>     
<li class="itemize">NOTS—Not Off-The-Shelf</li></ul>


<!-- l. 8 -->
<p class="indent">   A compliant Risk Management Framework (RMF) software list or Software Bill of Materials (S-BoM) manages
the different approval paths for these types of software.
</p>
<!-- l. 10 -->
<p class="noindent">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.1   </span> <a id="x1-20001.1"/>Identifying the Software</h4>


<!-- l. 12 -->
<p class="noindent">COTS software includes any software built for non-government, public activity. While COTS software implies a
commercial aspect to the application, open-source and public domain software are also included in the definition of
COTS software. While Shareware, Freeware, Adware, and as-is trial software are also COTS, they require explicit
Army SISO approval on each system they’re installed on and are not considered as part of this article.[<a href="#cite.0@20210405-ar25-2">3</a>, 4–12.a.6]
Open source components should be treated as any other COTS software for approval in a system. Each COTS
component is listed in the system’s software list, tracked by the change control board, and updates are subscribed
to by a member of the security team. After listing the COTS software in the software list, its procurement (license
costs and support information) are recorded in the system’s Army Portfolio Management Solution (APMS)
record. Remember that stand-alone COTS software should never be placed alone into APMS. Doing so
will cause the APMS records to indicate that the Army is paying multiple times for software and
has been used as an attempt to inflate budgets. The procurement cost for the software is dependent
upon the system implementing the software and is recorded in each implementing system’s APMS
record.
</p>
<!-- l. 14 -->
<p class="indent">   GOTS software is software that is not sold commercially or provided publicly. It is software created for or owned
by a government agency. This doesn’t mean that commercial/contractor providers don’t own the software. GOTS
software falls into three sub-categories:
</p>
     

<ol class="enumerate1">
<li class="enumerate" id="x1-2002x1">     
<i>GOTS software created by direction of the government for a particular purpose.</i> This software is then
owned by the public domain (owned by the taxpayers) and is generally easy to share with other
government agencies or protect at appropriate levels.
</li>     
<li class="enumerate" id="x1-2004x2">
<i>GOTS software created by a company or individual for fulfilling a government-directed duty.</i> When
the government gives direction to create software, this should include contract language to direct the
company creating it. By default, the restrictions of DFARS, specifically 48 CFR § 252.227-7014, apply
to the software.
</li>     
<li class="enumerate" id="x1-2006x3">
<i>Software assigned to government ownership.</i> When software is created by the government, it falls
under non-copyrighted public-domain software. When a copyright holder assigns copyright to the US,
the software is treated as public-domain, but the attribution of copyright assignment is retained for
non-repudiation purposes. You will see something like, “Copyright © 2020 Jon Hood; assigned to US
government on 8/9/2020” in the source files. There must be a valid previous copyright holder to assign
the copyright to the government.</li></ol>

                                                                                         
                                                                                         

<!-- l. 21 -->
<p class="noindent">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.2   </span> <a id="x1-30001.2"/>Assessing the Software</h4>


<!-- l. 23 -->
<p class="noindent">COTS products can be assessed in multiple ways: </p>


<ul class="itemize1">     
<li class="itemize">If the COTS product has an official Security Technical Implementation Guide (STIG) or Security
Requirements Guide (SRG), it is approved by DISA and reciprocity allows its use throughout the DoD.
The software is assessed in the implementing environment by applying the STIG/SRG.
</li>     
<li class="itemize">If the COTS software has no STIG or SRG, Software Assurance (SwA) is performed on the
product.
<ul class="itemize2">         
<li class="itemize">If the software has source code available, it is scanned using static source analysis. The Application
Security and Development (ASD) STIG is filled out and supplied, along with the SA-11* controls.
</li>         
<li class="itemize">If the software does not have source code and the product is being assessed for mission support
functionality, a dynamic binary analysis scan is performed. SA-11* controls are filled out and a
partial STIG report is provided.
</li>         
<li class="itemize">If the software is being used in a mission essential or mission critical environment, particularly
on tactical systems, a static binary analysis with reverse engineering is recommended. The ASD
STIG and any relevant SA-11* controls are completed.</li></ul>
</li></ul>


<!-- l. 34 -->
<p class="indent">   When filling out the ASD STIG for COTS software, several of the checks deal with a development environment
that is not geared towards developing the software for a government environment. Checks that pertain to
development processes and requirements can be marked as Not Applicable because the COTS software has
already been selected because it fulfills a requirements for a particular mission. If a mission dictates
new requirements that require custom development, that development should consider falling under
GOTS.
</p>
<!-- l. 36 -->
<p class="indent">   For GOTS software, the software is first assessed for compliance from a legal perspective: </p>


<ul class="itemize1">     
<li class="itemize">Is the software in the public domain with source code available?
</li>     
<li class="itemize">Does  the  software  meet  the  definition  of  “computer  software”  under  GOTS  Fdederal  Acquisition
Regulation (FAR) definitions?</li></ul>


<!-- l. 41 -->
<p class="noindent">If the software is GOTS, you will have the entirety of instructions for how to build the software. This is the legal
definition of GOTS. If you cannot build the software or are not provided the source code, the software does not meet
the definition of GOTS computer software per the FAR.
</p>
<!-- l. 43 -->
<p class="indent">   Once the software has been identified as GOTS, the ASD STIG is evaluated and any relevant SA-11 controls are
tailored in to the RMF control selection.
</p>
<!-- l. 45 -->
<p class="indent">   There is a final class of software that pretends to be GOTS but does not provide source code or build
instructions. This is considered “NOTS” software. This is often proprietary or IP-protected code, written at
taxpayer expense, and not provided back to the public. Instead, contractors and civilians attempt to re-sell the
software repeatedly back to the taxpayers who funded its development. This is why the DFARS regulations
under 48 CFR § 252.227-7014 were written. Note the very definition of computer software to fall under
DFARS’s definition of restricted rights GOTS software (emphasis added): “Computer software means
computer programs, <strong>source code</strong>, source code listings, object code listings, design details, algorithms,
processes, flow charts, formulae, and related material that would enable the software to be reproduced,
recreated, or recompiled. Computer software does not include computer databases or computer software
                                                                                         
                                                                                         
documentation.” By legal definition, you will have the source code and everything you need to rebuild the
source code to a working product if the software claims to be GOTS. A contractor may then say,
“Well, we’ll just say that the software is COTS then.” Now, that contractor must abide by the FAR
definitions of commercial software (FAR 2.101) and Non-Developmental Items. The software must
be:  
</p>


<blockquote class="quote">     
<!-- l. 46 --><p class="noindent">(i) A commercial item...;<br class="newline"/>(ii) Sold in substantial quantities in the commercial marketplace; and<br class="newline"/>(iii) Offered to the Government, under a contract or subcontract at any tier, without modification,
in the same form in which it is sold in the commercial marketplace;...[<a href="#cite.0@20210405-far">1</a>]</p></blockquote>


<!-- l. 50 -->
<p class="indent">   A piece of software that is not sold in a public, commercial marketplace is not COTS. Likewise, software that
does not provide source code and build instructions is not GOTS. These software packages are non-COTS,
non-GOTS, and simply ”not off-the-shelf” NOTS software that must have explicit AO approval and be tracked using
non-FAR-compliant acquisition processes.
</p>
<!-- l. 52 -->
<p class="indent">   Nevertheless, there is a non-trivial amount of NOTS software that is in use by the Army. Our
recommendation: perform a best-effort SwA scan, but also mark high-risk findings against the following checklists:
</p>
     

<ul class="itemize1">
<li class="itemize">On the ASD STIG, mark SV-222658r508029_rule (as of ASD V5R1) as a finding with the comment,
“The  support  contract  does  not  meet  the  requirements  of  COTS,  nor  does  the  application  meet
the definition of Computer Software for GOTS. COTS software must be procured through proper
acquisition channels (<a class="url" href="https://www.acquisition.gov/content/2101-definitions#i1125359"><span class="ec-lmtt-10">https://www.acquisition.gov/content/2101-definitions#i1125359</span></a>), and
GOTS computer software must provide source code and build instructions (48 CFR § 252.227-7014).”
</li>     
<li class="itemize">Tailor  in  (if  not  already  in  the  baseline)  and  mark  as  NON-COMPLIANT  RMF  control  SA-22,
CCI-3376 with the comment, “A software package does not provide either COTS or GOTS support
mechanisms.”
</li>     
<li class="itemize">Tailor in (if not already in the baseline) and mark as NON-COMPLIANT RMF control SA-4 (6),
CCI-631 with the comment, “The system employs software that is not COTS or GOTS.”</li></ul>


<!-- l. 59 -->
<p class="indent">   Note that RMF CCI-631 requires your software solutions to be either COTS or GOTS: “The organization
employs only government off-the-shelf (GOTS) or commercial off-the-shelf (COTS) information assurance (IA) and
IA-enabled information technology products that compose an NSA-approved solution to protect classified
information when the networks used to transmit the information are at a lower classification level than the
information being transmitted.” By attaching a finding to CCI-631, the program must include the finding in their
POA&amp;M for tracking and obtain AO approval for the non-compliant software.
                                                                                         
                                                                                         
</p>
   

<h3 class="sectionHead"><a id="x1-40001.2"/>References</h3>


<!-- l. 40 -->
<p class="noindent">    
</p>


<dl class="thebibliography"><dt class="thebibliography" id="X0-20210405-far">
[1]  
</dt><dd class="thebibliography" id="bib-1">
<!-- l. 40 --><p class="noindent"><a id="cite.0@20210405-far"/>GSA.    <span class="rm-lmri-10">Federal   Acuisition   Regulation.   Definitions</span>.    Department    of    Defense.    2019.    <span class="small-caps">url</span>:
<a class="url" href="https://www.acquisition.gov/far/2.101"><span class="ec-lmtt-10">https://www.acquisition.gov/far/2.101</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-swatips">
[2]  
</dt><dd class="thebibliography" id="bib-2">
<!-- l. 40 --><p class="noindent"><a id="cite.0@swatips"/>Jon Hood, ed. <span class="rm-lmri-10">SwATips</span>. <a class="url" href="https://www.SwATips.com/"><span class="ec-lmtt-10">https://www.SwATips.com/</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-20210405-ar25-2">
[3]  
</dt><dd class="thebibliography" id="bib-3">
<!-- l. 40 --><p class="noindent"><a id="cite.0@20210405-ar25-2"/>HQDA. <span class="rm-lmri-10">Army Regulation 25–2. Information Management: Information Assurance</span>. Department of the
Army.                 Washington,                 DC,                 USA,                 2019.                 <span class="small-caps">url</span>:
<a class="url" href="https://armypubs.army.mil/epubs/DR_pubs/DR_a/pdf/web/ARN17503_AR25_2_Admin_FINAL.pdf"><span class="ec-lmtt-10">https://armypubs.army.mil/epubs/DR_pubs/DR_a/pdf/web/ARN17503_AR25_2_Admin_FINAL.pdf</span></a>.</p></dd></dl>

 

]]></description>
	</item>
