	<item>
		<title>Sticking with a RAII Standard</title>
		<link>https://www.SwATips.com/articles/20210412.html</link>
		<pubDate>Mon, 12 Apr 2021 00:00:00 -0500</pubDate>
<description><![CDATA[
<p>Return to <a href="../">SwATips</a> | <a href="20210412.pdf">pdf</a></p>
<div class="maketitle">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a href="#cite.0@swatips">1</a>]<br/>
Generated Monday 12<sup class="textsuperscript">th</sup>&#xA0;April, 2021</h2>
<div class="author"><span class="rm-lmr-12">Jon Hood</span></div><br/>
<div class="date"><span class="rm-lmr-12">Monday 12</span><sup class="textsuperscript"><span class="rm-lmr-9">th</span></sup><span class="rm-lmr-12">&#xA0;April, 2021</span></div>
</div>
                                                                                         
                                                                                         
   
<h3 class="sectionHead"><span class="titlemark">1   </span> <a id="x1-10001"/>Sticking with a RAII Standard</h3>
<!-- l. 1 --><p class="noindent">Resource Acquisition Is Initialization (RAII). When working with legacy code, often variables and memory
management do not use RAII concepts. When memory is created in an uninitialized state, developers risk the use of
uninitialized memory further down in the application data flow.
</p><!-- l. 3 --><p class="indent">   To solve this, C++ implemented two ways of initializing new memory: <i>default</i> initialization and <i>value</i>
initialization. While default initialization is typically faster, developers quickly realized that there was rarely a
reason to keep memory uninitialized. Initializing memory as soon as it&#x2019;s allocated keeps developers from shooting
themselves in the foot.
</p><!-- l. 5 --><p class="indent">   One of the best ways to prevent memory errors is to use RAII. Particularly in exception-based code, RAII
concepts provide a memory-safe technique for resource management.[<a href="#cite.0@20210412-stroustrup2001">2</a>] Several issues face developers when
maintaining legacy code with new programming concepts, particularly in the DoD. Legacy code is
generally void of RAII concepts and has not been built with the latest standards of safe programming
practices.
</p><!-- l. 7 --><p class="noindent">
</p>   
<h4 class="subsectionHead"><span class="titlemark">1.1   </span> <a id="x1-20001.1"/>Updating the Code</h4>
<!-- l. 9 --><p class="noindent">The first option for maintaining legacy code in a memory-safe way is to update the code. Wrapping old pointers in
smart pointers can help make the code more maintainable.
</p>   
<!-- l. 11 -->
<p><a id="x1-2001r1"/></p>
<p><a id="x1-2002"/></p>   
<div id="listing-1" class="lstlisting"><span class="label"><a id="x1-2003r1"/></span><span class="ec-lmtt-9">bool&#xA0;*newBool&#xA0;=&#xA0;new&#xA0;bool();&#xA0;</span><br/><span class="label"><a id="x1-2004r2"/></span><span class="ec-lmtk-10x-x-90">if</span><span class="ec-lmtt-9">&#xA0;(*newBool)&#xA0;</span><br/><span class="label"><a id="x1-2005r3"/></span><span class="ec-lmtt-9">&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;cout&#xA0;&lt;&lt;&#xA0;"We&#x2019;re&#x2423;true!"&#xA0;&lt;&lt;&#xA0;endl;&#xA0;</span><br/><span class="label"><a id="x1-2006r4"/></span><span class="ec-lmtk-10x-x-90">else</span><span class="ec-lmtt-9">&#xA0;</span><br/><span class="label"><a id="x1-2007r5"/></span><span class="ec-lmtt-9">&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;cout&#xA0;&lt;&lt;&#xA0;"We&#x2019;re&#x2423;false!"&#xA0;&lt;&lt;&#xA0;endl;&#xA0;</span><br/><span class="label"><a id="x1-2008r6"/></span><span class="ec-lmtt-9">delete&#xA0;newBool;</span>
<figcaption class="caption"><span class="id">Listing&#xA0;1:</span><span class="content">Non-compliant listing</span></figcaption><!-- tex4ht:label?: x1-2001r1  -->
   
</div>
<!-- l. 20 -->
<p><a id="x1-2009r2"/></p>
<p><a id="x1-2010"/></p>   
<div id="listing-2" class="lstlisting"><span class="label"><a id="x1-2011r1"/></span><span class="ec-lmtk-10x-x-90">auto</span><span class="ec-lmtt-9">&#xA0;newBool&#xA0;=&#xA0;make_shared&lt;bool&gt;();&#xA0;</span><br/><span class="label"><a id="x1-2012r2"/></span><span class="ec-lmtti-10x-x-90">//Another&#xA0;way:&#xA0;shared_ptr&lt;bool&gt;&#xA0;newBool(new&#xA0;bool());</span><span class="ec-lmtt-9">&#xA0;</span><br/><span class="label"><a id="x1-2013r3"/></span><span class="ec-lmtk-10x-x-90">if</span><span class="ec-lmtt-9">&#xA0;(*newBool)&#xA0;</span><br/><span class="label"><a id="x1-2014r4"/></span><span class="ec-lmtt-9">&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;cout&#xA0;&lt;&lt;&#xA0;"We&#x2019;re&#x2423;true!"&#xA0;&lt;&lt;&#xA0;endl;&#xA0;</span><br/><span class="label"><a id="x1-2015r5"/></span><span class="ec-lmtk-10x-x-90">else</span><span class="ec-lmtt-9">&#xA0;</span><br/><span class="label"><a id="x1-2016r6"/></span><span class="ec-lmtt-9">&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;cout&#xA0;&lt;&lt;&#xA0;"We&#x2019;re&#x2423;false!"&#xA0;&lt;&lt;&#xA0;endl;</span>
<figcaption class="caption"><span class="id">Listing&#xA0;2:</span><span class="content">RAII-compliant listing</span></figcaption><!-- tex4ht:label?: x1-2009r1  -->
   
</div>
<!-- l. 29 --><p class="indent">   There are several issues with updating the old code to the RAII-compliant code:
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
                                                                                         
                                                                                         
<!-- l. 37 --><p class="noindent">
</p>   
<h4 class="subsectionHead"><span class="titlemark">1.2   </span> <a id="x1-30001.2"/>Double Frees</h4>
<!-- l. 39 --><p class="noindent">Developers can introduce double free conditions where a pointer is managed by both a smart pointer and in the
code itself. Also, conditions arise when a single pointer is handed over to multiple smart pointers for
management.
</p><!-- l. 41 --><p class="indent">   At the time of this writing, the latest versions of Fortify, Coverity, Checkmarx, Parasoft, clang-analyzer, and the
GCC 10 <span class="ec-lmtt-10">-fanalyzer </span>flag are all incapable of identifying the double free in the following snippets:
</p>   
<!-- l. 43 -->
<p><a id="x1-3001r3"/></p>
<p><a id="x1-3002"/></p>   
<div id="listing-3" class="lstlisting"><span class="label"><a id="x1-3003r1"/></span><span class="ec-lmtt-9">bool&#xA0;*newBool&#xA0;=&#xA0;new&#xA0;bool();&#xA0;</span><br/><span class="label"><a id="x1-3004r2"/></span><span class="ec-lmtt-9">shared_ptr&lt;bool&gt;&#xA0;test1&#xA0;(newBool);&#xA0;</span><br/><span class="label"><a id="x1-3005r3"/></span><span class="ec-lmtt-9">shared_ptr&lt;bool&gt;&#xA0;test2&#xA0;(newBool);&#xA0;</span><br/><span class="label"><a id="x1-3006r4"/></span><span class="ec-lmtti-10x-x-90">//...</span>
<figcaption class="caption"><span class="id">Listing&#xA0;3:</span><span class="content">Double Smart Pointer</span></figcaption><!-- tex4ht:label?: x1-3001r1  -->
   
</div>
<!-- l. 50 -->
<p><a id="x1-3007r4"/></p>
<p><a id="x1-3008"/></p>   
<div id="listing-4" class="lstlisting"><span class="label"><a id="x1-3009r1"/></span><span class="ec-lmtt-9">bool&#xA0;*newBool&#xA0;=&#xA0;new&#xA0;bool();&#xA0;</span><br/><span class="label"><a id="x1-3010r2"/></span><span class="ec-lmtt-9">shared_ptr&lt;bool&gt;&#xA0;test1&#xA0;(newBool);&#xA0;</span><br/><span class="label"><a id="x1-3011r3"/></span><span class="ec-lmtti-10x-x-90">//...</span><span class="ec-lmtt-9">&#xA0;</span><br/><span class="label"><a id="x1-3012r4"/></span><span class="ec-lmtt-9">delete&#xA0;newBool;</span>
<figcaption class="caption"><span class="id">Listing&#xA0;4:</span><span class="content">Smart and Dumb Pointer</span></figcaption><!-- tex4ht:label?: x1-3007r1  -->
   
</div>
<!-- l. 57 --><p class="noindent">
</p>   
<h4 class="subsectionHead"><span class="titlemark">1.3   </span> <a id="x1-40001.3"/>Initialization Errors</h4>
<!-- l. 59 --><p class="noindent">We&#x2019;ve also seen a large number of initialization errors when updating to smart pointers. Using the above examples,
it&#x2019;s tempting for a developer to use shortcuts and do something like the following:
</p>   
<!-- l. 61 -->
<p><a id="x1-4001r5"/></p>
<p><a id="x1-4002"/></p>   
<div id="listing-5" class="lstlisting"><span class="label"><a id="x1-4003r1"/></span><span class="ec-lmtt-9">shared_ptr&lt;bool&gt;&#xA0;test1&#xA0;(new&#xA0;bool);&#xA0;</span><br/><span class="label"><a id="x1-4004r2"/></span><span class="ec-lmtt-9">cout&#xA0;&lt;&lt;&#xA0;"Test1&#x2423;is:&#x2423;"&#xA0;&lt;&lt;&#xA0;*test1&#xA0;&lt;&lt;&#xA0;endl;</span>
<figcaption class="caption"><span class="id">Listing&#xA0;5:</span><span class="content">Uninitialized Boolean</span></figcaption><!-- tex4ht:label?: x1-4001r1  -->
   
</div>
<!-- l. 66 --><p class="indent">   The unpredictable nature of this issue can be demonstrated in the following example where the Boolean uses
default initialization and obtains a random value from previously-freed memory.
</p>   
<!-- l. 68 -->
<p><a id="x1-4005r6"/></p>
<p><a id="x1-4006"/></p>   
<div id="listing-6" class="lstlisting"><span class="label"><a id="x1-4007r1"/></span><span class="ec-lmtk-10x-x-90">#include</span><span class="ec-lmtt-9">&#xA0;&lt;climits&gt;&#xA0;</span><br/><span class="label"><a id="x1-4008r2"/></span><span class="ec-lmtk-10x-x-90">#include</span><span class="ec-lmtt-9">&#xA0;&lt;iostream&gt;&#xA0;</span><br/><span class="label"><a id="x1-4009r3"/></span><span class="ec-lmtk-10x-x-90">#include</span><span class="ec-lmtt-9">&#xA0;&lt;memory&gt;&#xA0;</span><br/><span class="label"><a id="x1-4010r4"/></span><span class="ec-lmtk-10x-x-90">#include</span><span class="ec-lmtt-9">&#xA0;&lt;random&gt;&#xA0;</span><br/><span class="label"><a id="x1-4011r5"/></span><span class="ec-lmtt-9">using&#xA0;namespace&#xA0;std;&#xA0;</span><br/><span class="label"><a id="x1-4012r6"/></span><span class="ec-lmtk-10x-x-90">int</span><span class="ec-lmtt-9">&#xA0;main()&#xA0;</span><br/><span class="label"><a id="x1-4013r7"/></span><span class="ec-lmtt-9">{&#xA0;</span><br/><span class="label"><a id="x1-4014r8"/></span><span class="ec-lmtt-9">&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;random_device&#xA0;rd;&#xA0;</span><br/><span class="label"><a id="x1-4015r9"/></span><span class="ec-lmtt-9">&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;mt19937&#xA0;gen(rd());&#xA0;</span><br/><span class="label"><a id="x1-4016r10"/></span><span class="ec-lmtt-9">&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;uniform_int_distribution&lt;&gt;&#xA0;distrib(INT_MIN,&#xA0;INT_MAX);&#xA0;</span><br/><span class="label"><a id="x1-4017r11"/></span><span class="ec-lmtt-9">&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;vector&lt;</span><span class="ec-lmtk-10x-x-90">int</span><span class="ec-lmtt-9">*&gt;&#xA0;deleteLater;&#xA0;</span><br/><span class="label"><a id="x1-4018r12"/></span><span class="ec-lmtt-9">&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;</span><span class="ec-lmtk-10x-x-90">for</span><span class="ec-lmtt-9">&#xA0;(</span><span class="ec-lmtk-10x-x-90">int</span><span class="ec-lmtt-9">&#xA0;i&#xA0;=&#xA0;0;&#xA0;i&#xA0;&lt;&#xA0;100;&#xA0;i++)&#xA0;</span><br/><span class="label"><a id="x1-4019r13"/></span><span class="ec-lmtt-9">&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;{&#xA0;</span><br/><span class="label"><a id="x1-4020r14"/></span><span class="ec-lmtt-9">&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;</span><span class="ec-lmtk-10x-x-90">int</span><span class="ec-lmtt-9">&#xA0;*deleteMe&#xA0;=&#xA0;new&#xA0;</span><span class="ec-lmtk-10x-x-90">int</span><span class="ec-lmtt-9">;&#xA0;</span><br/><span class="label"><a id="x1-4021r15"/></span><span class="ec-lmtt-9">&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;*deleteMe&#xA0;=&#xA0;distrib(gen);&#xA0;</span><br/><span class="label"><a id="x1-4022r16"/></span><span class="ec-lmtti-10x-x-90">&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;//delete&#xA0;some&#xA0;memory&#xA0;now</span><span class="ec-lmtt-9">&#xA0;</span><br/><span class="label"><a id="x1-4023r17"/></span><span class="ec-lmtt-9">&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;</span><span class="ec-lmtk-10x-x-90">if</span><span class="ec-lmtt-9">&#xA0;(*deleteMe&#xA0;&gt;&#xA0;0)&#xA0;</span><br/><span class="label"><a id="x1-4024r18"/></span><span class="ec-lmtt-9">&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;delete&#xA0;deleteMe;&#xA0;</span><br/><span class="label"><a id="x1-4025r19"/></span><span class="ec-lmtt-9">&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;</span><span class="ec-lmtk-10x-x-90">else</span><span class="ec-lmtt-9">&#xA0;</span><br/><span class="label"><a id="x1-4026r20"/></span><span class="ec-lmtt-9">&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;deleteLater.push_back(deleteMe);&#xA0;</span><br/><span class="label"><a id="x1-4027r21"/></span><span class="ec-lmtt-9">&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;}&#xA0;</span><br/><span class="label"><a id="x1-4028r22"/></span><span class="ec-lmtt-9">&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;shared_ptr&lt;bool&gt;&#xA0;newBool(new&#xA0;bool);&#xA0;</span><br/><span class="label"><a id="x1-4029r23"/></span><span class="ec-lmtt-9">&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;cout&#xA0;&lt;&lt;&#xA0;"Value:&#x2423;"&#xA0;&lt;&lt;&#xA0;*newBool&#xA0;&lt;&lt;&#xA0;endl;&#xA0;</span><br/><span class="label"><a id="x1-4030r24"/></span><span class="ec-lmtti-10x-x-90">&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;//delete&#xA0;some&#xA0;memory&#xA0;later</span><span class="ec-lmtt-9">&#xA0;</span><br/><span class="label"><a id="x1-4031r25"/></span><span class="ec-lmtt-9">&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;</span><span class="ec-lmtk-10x-x-90">for</span><span class="ec-lmtt-9">&#xA0;(</span><span class="ec-lmtk-10x-x-90">int</span><span class="ec-lmtt-9">&#xA0;*n&#xA0;:&#xA0;deleteLater)&#xA0;</span><br/><span class="label"><a id="x1-4032r26"/></span><span class="ec-lmtt-9">&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;delete&#xA0;n;&#xA0;</span><br/><span class="label"><a id="x1-4033r27"/></span><span class="ec-lmtt-9">&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;</span><span class="ec-lmtk-10x-x-90">return</span><span class="ec-lmtt-9">&#xA0;0;&#xA0;</span><br/><span class="label"><a id="x1-4034r28"/></span><span class="ec-lmtt-9">}</span>
<figcaption class="caption"><span class="id">Listing&#xA0;6:</span><span class="content">Uninitialized Boolean</span></figcaption><!-- tex4ht:label?: x1-4005r1  -->
   
</div>
                                                                                         
                                                                                         
<!-- l. 99 --><p class="noindent">
</p>   
<h4 class="subsectionHead"><span class="titlemark">1.4   </span> <a id="x1-50001.4"/>Inconsistency Can Increase Maintenance Costs</h4>
<!-- l. 101 --><p class="noindent">Consider updated code that uses a multitude of different memory handling methods. Some memory is managed
manually using <span class="ec-lmtt-10">malloc </span>and <span class="ec-lmtt-10">free</span>. Some pass the previous pointer values to smart pointers for their management.
Others have been updated to use the <span class="ec-lmtt-10">make_shared </span>construct. Still others have been updated to custom classes and
structs.
</p><!-- l. 103 --><p class="indent">   Consistency is more important than updating. Introducing multiple memory handling patterns to a section of
code increases its complexity. If old memory handling methods cannot be replaced or are not planned to be replaced,
it may make more sense to stick with confusing (but consistent) code rather than adding additional
complexity.
</p><!-- l. 105 --><p class="noindent">
</p>   
<h4 class="subsectionHead"><span class="titlemark">1.5   </span> <a id="x1-60001.5"/>Smart Pointers and Arrays</h4>
<!-- l. 107 --><p class="noindent">Finally, some special considerations are needed for allowing smart pointers to handle arrays. The <span class="ec-lmtt-10">shared_ptr</span>
construct permits the developer to define a custom deleter like the one for this array of 10 Booleans:
</p>   
<!-- l. 109 -->
<p><a id="x1-6001r7"/></p>
<p><a id="x1-6002"/></p>   
<div id="listing-7" class="lstlisting"><span class="label"><a id="x1-6003r1"/></span><span class="ec-lmtt-9">shared_ptr&lt;bool&gt;&#xA0;test1{&#xA0;</span><br/><span class="label"><a id="x1-6004r2"/></span><span class="ec-lmtt-9">&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;&#xA0;new&#xA0;bool[10],&#xA0;[](</span><span class="ec-lmtk-10x-x-90">const</span><span class="ec-lmtt-9">&#xA0;bool&#xA0;*ptr)&#xA0;{&#xA0;delete&#xA0;[]&#xA0;ptr;&#xA0;}&#xA0;</span><br/><span class="label"><a id="x1-6005r3"/></span><span class="ec-lmtt-9">};</span>
<figcaption class="caption"><span class="id">Listing&#xA0;7:</span><span class="content">Custom Deleter</span></figcaption><!-- tex4ht:label?: x1-6001r1  -->
   
</div>
<!-- l. 115 --><p class="noindent">
</p>   
<h4 class="subsectionHead"><span class="titlemark">1.6   </span> <a id="x1-70001.6"/>Conclusion</h4>
<!-- l. 117 --><p class="noindent">Smart pointers and RAII concepts help developers prevent memory errors that can plague software. Updating legacy
code to RAII concepts can increase its maintainability, usefulness, and security. Nevertheless, updates to the code
should not come at a price of inconsistency. When updates can only be applied partially or introduce additional
complexity, consistency should be preferred.
                                                                                         
                                                                                         
</p>   
<h3 class="sectionHead"><a id="x1-80001.6"/>References</h3>
<!-- l. 45 --><p class="noindent">    
</p>
<dl class="thebibliography"><dt id="X0-swatips" class="thebibliography">
[1]  
</dt><dd id="bib-1" class="thebibliography">
<!-- l. 45 --><p class="noindent"><a id="cite.0@swatips"/>Jon Hood, ed. <span class="rm-lmri-10">SwATips</span>. <a href="https://www.SwATips.com/" class="url"><span class="ec-lmtt-10">https://www.SwATips.com/</span></a>.
</p>    
</dd>
<dt id="X0-20210412-stroustrup2001" class="thebibliography">
[2]  
</dt><dd id="bib-2" class="thebibliography">
<!-- l. 45 --><p class="noindent"><a id="cite.0@20210412-stroustrup2001"/>Bjarne    Stroustrup.    &#x201C;Exception    Safety:    Concepts    and    Techniques&#x201D;.    In:    (2001).    <span class="small-caps">url</span>:
<a href="https://www.stroustrup.com/except.pdf" class="url"><span class="ec-lmtt-10">https://www.stroustrup.com/except.pdf</span></a>.</p></dd></dl>
 
]]></description>
	</item>
	<item>
		<title>COTS, GOTS, and NOTS software in RMF for the Army</title>
		<link>https://www.SwATips.com/articles/20210405.html</link>
		<pubDate>Mon, 05 Apr 2021 00:00:00 -0500</pubDate>
<description><![CDATA[
<p>Return to <a href="../">SwATips</a> | <a href="20210405.pdf">pdf</a></p>
<div class="maketitle">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a href="#cite.0@swatips">2</a>]<br/>
Generated Monday 5<sup class="textsuperscript">th</sup>&#xA0;April, 2021</h2>
<div class="author"><span class="rm-lmr-12">Jon Hood</span></div><br/>
<div class="date"><span class="rm-lmr-12">Monday 5</span><sup class="textsuperscript"><span class="rm-lmr-9">th</span></sup><span class="rm-lmr-12">&#xA0;April, 2021</span></div>
</div>
                                                                                         
                                                                                         
   
<h3 class="sectionHead"><span class="titlemark">1   </span> <a id="x1-10001"/>COTS, GOTS, and NOTS software in RMF for the Army</h3>
<!-- l. 1 --><p class="noindent">When working as a government contractor security professional for a system that includes custom software, three
different classes of software must be considered as part of the RMF process: </p>
<ul class="itemize1">     
<li class="itemize">COTS&#x2014;Commercial Off-The-Shelf
</li>     
<li class="itemize">GOTS&#x2014;Government Off-The-Shelf
</li>     
<li class="itemize">NOTS&#x2014;Not Off-The-Shelf</li></ul>
<!-- l. 8 --><p class="indent">   A compliant Risk Management Framework (RMF) software list or Software Bill of Materials (S-BoM) manages
the different approval paths for these types of software.
</p><!-- l. 10 --><p class="noindent">
</p>   
<h4 class="subsectionHead"><span class="titlemark">1.1   </span> <a id="x1-20001.1"/>Identifying the Software</h4>
<!-- l. 12 --><p class="noindent">COTS software includes any software built for non-government, public activity. While COTS software implies a
commercial aspect to the application, open-source and public domain software are also included in the definition of
COTS software. While Shareware, Freeware, Adware, and as-is trial software are also COTS, they require explicit
Army SISO approval on each system they&#x2019;re installed on and are not considered as part of this article.[<a href="#cite.0@20210405-ar25-2">3</a>, 4&#x2013;12.a.6]
Open source components should be treated as any other COTS software for approval in a system. Each COTS
component is listed in the system&#x2019;s software list, tracked by the change control board, and updates are subscribed
to by a member of the security team. After listing the COTS software in the software list, its procurement (license
costs and support information) are recorded in the system&#x2019;s Army Portfolio Management Solution (APMS)
record. Remember that stand-alone COTS software should never be placed alone into APMS. Doing so
will cause the APMS records to indicate that the Army is paying multiple times for software and
has been used as an attempt to inflate budgets. The procurement cost for the software is dependent
upon the system implementing the software and is recorded in each implementing system&#x2019;s APMS
record.
</p><!-- l. 14 --><p class="indent">   GOTS software is software that is not sold commercially or provided publicly. It is software created for or owned
by a government agency. This doesn&#x2019;t mean that commercial/contractor providers don&#x2019;t own the software. GOTS
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
company creating it. By default, the restrictions of DFARS, specifically 48 CFR &#xA7; 252.227-7014, apply
to the software.
</li>     
<li class="enumerate" id="x1-2006x3">
<i>Software assigned to government ownership.</i> When software is created by the government, it falls
under non-copyrighted public-domain software. When a copyright holder assigns copyright to the US,
the software is treated as public-domain, but the attribution of copyright assignment is retained for
non-repudiation purposes. You will see something like, &#x201C;Copyright &#xA9; 2020 Jon Hood; assigned to US
government on 8/9/2020&#x201D; in the source files. There must be a valid previous copyright holder to assign
the copyright to the government.</li></ol>
                                                                                         
                                                                                         
<!-- l. 21 --><p class="noindent">
</p>   
<h4 class="subsectionHead"><span class="titlemark">1.2   </span> <a id="x1-30001.2"/>Assessing the Software</h4>
<!-- l. 23 --><p class="noindent">COTS products can be assessed in multiple ways: </p>
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
<!-- l. 34 --><p class="indent">   When filling out the ASD STIG for COTS software, several of the checks deal with a development environment
that is not geared towards developing the software for a government environment. Checks that pertain to
development processes and requirements can be marked as Not Applicable because the COTS software has
already been selected because it fulfills a requirements for a particular mission. If a mission dictates
new requirements that require custom development, that development should consider falling under
GOTS.
</p><!-- l. 36 --><p class="indent">   For GOTS software, the software is first assessed for compliance from a legal perspective: </p>
<ul class="itemize1">     
<li class="itemize">Is the software in the public domain with source code available?
</li>     
<li class="itemize">Does  the  software  meet  the  definition  of  &#x201C;computer  software&#x201D;  under  GOTS  Fdederal  Acquisition
Regulation (FAR) definitions?</li></ul>
<!-- l. 41 --><p class="noindent">If the software is GOTS, you will have the entirety of instructions for how to build the software. This is the legal
definition of GOTS. If you cannot build the software or are not provided the source code, the software does not meet
the definition of GOTS computer software per the FAR.
</p><!-- l. 43 --><p class="indent">   Once the software has been identified as GOTS, the ASD STIG is evaluated and any relevant SA-11 controls are
tailored in to the RMF control selection.
</p><!-- l. 45 --><p class="indent">   There is a final class of software that pretends to be GOTS but does not provide source code or build
instructions. This is considered &#x201C;NOTS&#x201D; software. This is often proprietary or IP-protected code, written at
taxpayer expense, and not provided back to the public. Instead, contractors and civilians attempt to re-sell the
software repeatedly back to the taxpayers who funded its development. This is why the DFARS regulations
under 48 CFR &#xA7; 252.227-7014 were written. Note the very definition of computer software to fall under
DFARS&#x2019;s definition of restricted rights GOTS software (emphasis added): &#x201C;Computer software means
computer programs, <strong>source code</strong>, source code listings, object code listings, design details, algorithms,
processes, flow charts, formulae, and related material that would enable the software to be reproduced,
recreated, or recompiled. Computer software does not include computer databases or computer software
                                                                                         
                                                                                         
documentation.&#x201D; By legal definition, you will have the source code and everything you need to rebuild the
source code to a working product if the software claims to be GOTS. A contractor may then say,
&#x201C;Well, we&#x2019;ll just say that the software is COTS then.&#x201D; Now, that contractor must abide by the FAR
definitions of commercial software (FAR 2.101) and Non-Developmental Items. The software must
be:  
</p>
<blockquote class="quote">     
<!-- l. 46 --><p class="noindent">(i) A commercial item...;<br class="newline"/>(ii) Sold in substantial quantities in the commercial marketplace; and<br class="newline"/>(iii) Offered to the Government, under a contract or subcontract at any tier, without modification,
in the same form in which it is sold in the commercial marketplace;...[<a href="#cite.0@20210405-far">1</a>]</p></blockquote>
<!-- l. 50 --><p class="indent">   A piece of software that is not sold in a public, commercial marketplace is not COTS. Likewise, software that
does not provide source code and build instructions is not GOTS. These software packages are non-COTS,
non-GOTS, and simply &#x201D;not off-the-shelf&#x201D; NOTS software that must have explicit AO approval and be tracked using
non-FAR-compliant acquisition processes.
</p><!-- l. 52 --><p class="indent">   Nevertheless, there is a non-trivial amount of NOTS software that is in use by the Army. Our
recommendation: perform a best-effort SwA scan, but also mark high-risk findings against the following checklists:
</p>     
<ul class="itemize1">
<li class="itemize">On the ASD STIG, mark SV-222658r508029_rule (as of ASD V5R1) as a finding with the comment,
&#x201C;The  support  contract  does  not  meet  the  requirements  of  COTS,  nor  does  the  application  meet
the definition of Computer Software for GOTS. COTS software must be procured through proper
acquisition channels (<a class="url" href="https://www.acquisition.gov/content/2101-definitions#i1125359"><span class="ec-lmtt-10">https://www.acquisition.gov/content/2101-definitions#i1125359</span></a>), and
GOTS computer software must provide source code and build instructions (48 CFR &#xA7; 252.227-7014).&#x201D;
</li>     
<li class="itemize">Tailor  in  (if  not  already  in  the  baseline)  and  mark  as  NON-COMPLIANT  RMF  control  SA-22,
CCI-3376 with the comment, &#x201C;A software package does not provide either COTS or GOTS support
mechanisms.&#x201D;
</li>     
<li class="itemize">Tailor in (if not already in the baseline) and mark as NON-COMPLIANT RMF control SA-4 (6),
CCI-631 with the comment, &#x201C;The system employs software that is not COTS or GOTS.&#x201D;</li></ul>
<!-- l. 59 --><p class="indent">   Note that RMF CCI-631 requires your software solutions to be either COTS or GOTS: &#x201C;The organization
employs only government off-the-shelf (GOTS) or commercial off-the-shelf (COTS) information assurance (IA) and
IA-enabled information technology products that compose an NSA-approved solution to protect classified
information when the networks used to transmit the information are at a lower classification level than the
information being transmitted.&#x201D; By attaching a finding to CCI-631, the program must include the finding in their
POA&amp;M for tracking and obtain AO approval for the non-compliant software.
                                                                                         
                                                                                         
</p>   
<h3 class="sectionHead"><a id="x1-40001.2"/>References</h3>
<!-- l. 40 --><p class="noindent">    
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
<!-- l. 40 --><p class="noindent"><a id="cite.0@20210405-ar25-2"/>HQDA. <span class="rm-lmri-10">Army Regulation 25&#x2013;2. Information Management: Information Assurance</span>. Department of the
Army.                 Washington,                 DC,                 USA,                 2019.                 <span class="small-caps">url</span>:
<a class="url" href="https://armypubs.army.mil/epubs/DR_pubs/DR_a/pdf/web/ARN17503_AR25_2_Admin_FINAL.pdf"><span class="ec-lmtt-10">https://armypubs.army.mil/epubs/DR_pubs/DR_a/pdf/web/ARN17503_AR25_2_Admin_FINAL.pdf</span></a>.</p></dd></dl>
 
]]></description>
	</item>
