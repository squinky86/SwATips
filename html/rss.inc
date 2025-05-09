	<item>
		<title>Leaking Through the Cracks: Rust's Soft Memory Shell</title>
		<link>https://www.SwATips.com/articles/20250512.html</link>
		<pubDate>Mon, 12 May 2025 00:00:00 -0500</pubDate>
<description><![CDATA[

<p style="margin-top: 0; margin-bottom: 0;"><a href="/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/swatips.svg" width="120" alt="SwATips" style="border-top: 0; border-left: 0; border-right: 0;"/></a>| <a href="articles/20250512.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">pdf</a> | <a rel="license" href="http://creativecommons.org/licenses/by/4.0/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/by.svg" width="60" height="21" alt="CC-BY" style="border-top: 0; border-left: 0; border-right: 0;"/></a></p>


<div class="maketitle" style="margin-top: 1em; text-align: center; margin-bottom: 2em;">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead" style="line-height: 1.2; text-align: center;"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a id="x1-3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0_swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">3</a>]<br/>
</h2>
 <div class="author" style="text-align: center;"><span class="ec-lmr-12" style="font-size: 120%;">Jon Hood</span></div><br/>
<div class="date" style="text-align: center;"><span class="ec-lmr-12" style="font-size: 120%;">Monday 12</span><sup class="textsuperscript"><span class="ec-lmr-9" style="font-size: 90%;">th</span></sup><span class="ec-lmr-12" style="font-size: 120%;"> May, 2025</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead" style="line-height: 1.2; font-size: 1.5157em;"><span class="titlemark">1   </span> <a id="x1-10001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Leaking Through the Cracks: Rust’s Soft Memory Shell</h3>


<!-- l. 47 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;"><span class="ec-lmr-8" style="font-size: 80%;">Updated Friday 9</span><sup class="textsuperscript"><span class="ec-lmr-9" style="font-size: 90%;">th</span></sup><span class="ec-lmr-8" style="font-size: 80%;"> May, 2025</span>
</p>
<!-- l. 1 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Last year, Cybersecurity leadership in the U.S. encouraged organizations to use memory-safe programming
languages. I criticized the blanket recommendation[<a id="x1-1001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0_20250512_hood2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2</a>] as a partial solution for a more serious underlying concern in
developer training, citing the problems faced with legacy Ada code[<a id="x1-1002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0_20250512_hood" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1</a>]. Recently, I have had the privilege of sitting
through lengthy meetings extoling the virtues of memory-safe languages and creating policies that enumerate the
languages that developers must use for certain contracts. In spite of all the warnings, it looks like certain
government agencies are pushing ahead with the recommendation.
</p>
<!-- l. 3 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   But is requiring a memory-safe language the panacea to memory safety? Certainly not! Heap inspection, logical
errors caused by algorithm complexity, and memory leaks are not areas of memory safety guaranteed by Rust. After
appreciated and constructive criticism from my last article focusing on Ada, I have been politely asked to
demonstrate memory concerns that should be considered in Rust.
</p>
<!-- l. 5 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="likesubsectionHead" style="line-height: 1.2; font-size: 1.3195em;"><a id="x1-2000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Rust Background</h4>


<!-- l. 6 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">In “safe” code (and most of the development in Rust is safe by default unless you use the <span class="ec-lmtt-10" style="font-family: monospace,monospace;">unsafe </span>keyword), many of
the memory safety concerns have very strong mitigations. At compile time, the Rust borrow checker will prevent
most dangling pointers, use-after-free errors, memory-related TOCTOU and data race issues, invalid
memory accesses, and more. At runtime, additional checks will panic in ways that can be handled
appropriately.
</p>
<!-- l. 8 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   What doesn’t get caught, however, are the profundity of memory issues related to data confidentiality (heap
inspections), integrity (logical errors due to algorithm complexity), and availability (memory leaks and DoS attacks)
that plague safety-critical systems today.
</p>
<!-- l. 10 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="likesubsectionHead" style="line-height: 1.2; font-size: 1.3195em;"><a id="x1-3000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>A Demonstration of Memory Leaks</h4>


<!-- l. 12 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Consider the intentional memory leak in Listing <a href="#x1-3001r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1<!-- tex4ht:ref: lst:20250512:leak  --></a>.
</p>
   

<!-- l. 14 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-3001r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>
<a id="x1-3002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>   
</p>
<pre class="lstlisting" id="listing-1" style="font-family: monospace,monospace; white-space: pre-wrap; margin-top: 0.5em; margin-bottom: 0.5em; background-color: #BFBFBF;"><span class="label" style="margin-right: 0.5em;"><a id="x1-3003r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">use</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">std::rc::</span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">Rc</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">;</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3004r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">use</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">std::cell::</span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">RefCell</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">;</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3005r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">use</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">std::thread;</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3006r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">use</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">std::</span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">time</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">::</span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">Duration</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">;</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3007r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-3008r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#0000BF"><span class="ec-lmtti-10x-x-90" style="font-size: 90%; font-family: monospace,monospace; font-style: italic;">#[</span></span><span style="color:#0000BF"><span class="ec-lmtti-10x-x-90" style="font-size: 90%; font-family: monospace,monospace; font-style: italic;">derive</span></span><span style="color:#0000BF"><span class="ec-lmtti-10x-x-90" style="font-size: 90%; font-family: monospace,monospace; font-style: italic;">(</span></span><span style="color:#0000BF"><span class="ec-lmtti-10x-x-90" style="font-size: 90%; font-family: monospace,monospace; font-style: italic;">Debug</span></span><span style="color:#0000BF"><span class="ec-lmtti-10x-x-90" style="font-size: 90%; font-family: monospace,monospace; font-style: italic;">)</span></span><span style="color:#0000BF"><span class="ec-lmtti-10x-x-90" style="font-size: 90%; font-family: monospace,monospace; font-style: italic;">]</span></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-3009r7" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">struct</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">Node {</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3010r8" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">    </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">value</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">:</span></span><span style="color:#000000"> <span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">i32</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">,</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3011r9" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">    </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">next</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">:</span></span><span style="color:#000000"> <span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">RefCell</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">&lt;</span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">Option</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">&lt;</span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">Rc</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">&lt;Node&gt;&gt;&gt;,</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3012r10" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">}</span></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-3013r11" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-3014r12" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">fn</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">create_and_leak(n: </span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">i32</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">) {</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3015r13" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">    </span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">let</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">a = </span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">Rc</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">::new(Node { value: n + 1, next: </span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">RefCell</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">::new(</span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">None</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">) });</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3016r14" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">    </span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">let</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">b = </span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">Rc</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">::new(Node { value: n + 2, next: </span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">RefCell</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">::new(</span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">None</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">) });</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3017r15" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-3018r16" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">    </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">a</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">.</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">next</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">.</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">borrow_mut</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">().</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">replace</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">(</span></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">Rc</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">::</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">clone</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">(&amp;</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">b</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">));</span></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-3019r17" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">    </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">b</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">.</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">next</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">.</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">borrow_mut</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">().</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">replace</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">(</span></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">Rc</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">::</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">clone</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">(&amp;</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">a</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">));</span></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-3020r18" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-3021r19" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">    </span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">println!</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">(</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">"</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">Leaky</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">cycle {}.", a.value);</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3022r20" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">    </span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">println!</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">(</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">"</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">Reference</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">counts: a = {}, b = {}.", </span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">Rc</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">::strong_count(&amp;a), </span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">Rc</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">::strong_count(&amp;b));</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3023r21" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">    </span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">println!</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">(</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">"</span></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">Values</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">:</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">a = {}, b = {}.", a.value, b.value);</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3024r22" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-3025r23" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtti-10x-x-90" style="font-size: 90%; font-family: monospace,monospace; font-style: italic;">    </span><span style="color:#000000"><span class="ec-lmtti-10x-x-90" style="font-size: 90%; font-family: monospace,monospace; font-style: italic;">//</span></span><span style="color:#000000"> <span class="ts1-lmtti10-x-x-90" style="font-size: 90%;">'</span><span class="ec-lmtti-10x-x-90" style="font-size: 90%; font-family: monospace,monospace; font-style: italic;">a</span><span class="ts1-lmtti10-x-x-90" style="font-size: 90%;">' </span><span class="ec-lmtti-10x-x-90" style="font-size: 90%; font-family: monospace,monospace; font-style: italic;">and </span><span class="ts1-lmtti10-x-x-90" style="font-size: 90%;">'</span><span class="ec-lmtti-10x-x-90" style="font-size: 90%; font-family: monospace,monospace; font-style: italic;">b</span><span class="ts1-lmtti10-x-x-90" style="font-size: 90%;">' </span><span class="ec-lmtti-10x-x-90" style="font-size: 90%; font-family: monospace,monospace; font-style: italic;">go out of scope but are not deallocated.</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3026r24" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">}</span></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-3027r25" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-3028r26" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">fn</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">main() {</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3029r27" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">    </span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">println!</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">(</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">"</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">Starting</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">the main </span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">loop</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">...");</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3030r28" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">    </span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">for</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">i </span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">in </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">0..2 {</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3031r29" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">create_and_leak</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">(</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">i</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">);</span></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-3032r30" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">thread</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">::</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">sleep</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">(</span></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">Duration</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">::</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">from_secs</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">(1));</span></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-3033r31" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">    </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">}</span></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-3034r32" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">}</span></span></pre>


<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 1: </span><span class="content">leaky.rs: Intentional Memory Leak</span></figcaption>
<!-- tex4ht:label?: x1-3034r  -->


<!-- l. 49 -->
<p class="indent" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   The code can be compiled, executed, and run through the tool <span class="ec-lmtt-10" style="font-family: monospace,monospace;">heaptrack </span>on the command line as shown in
Listing <a href="#x1-3035r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2<!-- tex4ht:ref: lst:20250512:run  --></a>.
</p>
   

<!-- l. 51 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-3035r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>
<a id="x1-3036" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>   
</p>
<pre class="lstlisting" id="listing-2" style="font-family: monospace,monospace; white-space: pre-wrap; margin-top: 0.5em; margin-bottom: 0.5em; background-color: #BFBFBF;"><span class="label" style="margin-right: 0.5em;"><a id="x1-3037r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">$</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">rustc leaky.rs</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3038r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">$</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">heaptrack ./leaky</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3039r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">heaptrack</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">output will be written to "./heaptrack.leaky.10245.zst"</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3040r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">starting</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">application, this might take some time...</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3041r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">Starting</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">the main loop...</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3042r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">Leaky</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">cycle 1.</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3043r7" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">Reference</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">counts: a = 2, b = 2.</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3044r8" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">Values</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">:</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">a = 1, b = 2.</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3045r9" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">NOTE</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">:</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">heaptrack detected DEBUGINFOD_URLS but will disable it to prevent</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3046r10" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">unintended</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">network delays during recording</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3047r11" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">If</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">you really want to use DEBUGINFOD, </span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">export </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">HEAPTRACK_ENABLE_DEBUGINFOD=1</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3048r12" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">Leaky</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">cycle 2.</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3049r13" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">Reference</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">counts: a = 2, b = 2.</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3050r14" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">Values</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">:</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">a = 2, b = 3.</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3051r15" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">heaptrack</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">stats:</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3052r16" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">allocations</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">:</span></span><span style="color:#000000"> </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">          </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">19</span></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-3053r17" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">leaked</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">allocations:</span> </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">    </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">4</span></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-3054r18" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">temporary</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">allocations:</span> </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">1</span></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-3055r19" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">Heaptrack</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">finished! Now run the following to investigate the data:</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3056r20" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-3057r21" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">  </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">heaptrack</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">--analyze "./heaptrack.leaky.10245.zst"</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3058r22" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">$</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">heaptrack_print heaptrack.leaky.10245.zst | grep "^total memory"</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3059r23" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">total</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">memory leaked: 160B</span></span></pre>


<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 2: </span><span class="content">Heaptrack</span></figcaption>
<!-- tex4ht:label?: x1-3059r  -->

                                                                                         
                                                                                         

<!-- l. 77 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">
</p>
   

<h4 class="likesubsectionHead" style="line-height: 1.2; font-size: 1.3195em;"><a id="x1-4000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Conclusion</h4>


<!-- l. 78 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">In the mid-2000s, Gentoo Linux was at the height of its popularity. It had an active community and extremely
friendly documentation. The bugfixes, performance improvements, and security enhancements it brought to the
Linux community are a shining beacon of what new technologies can do for the overall community. In like manner,
Rust and other memory-safe languages are ushering in a new age security-conscious development. Proposals for
memory-safe C++, safety-critical Rust technologies like Ferrocene, and even experimental borrow
checkers in other languages have exploded onto the scene. The benefits of Rust cannot be overstated, and
the second-order effects of the Rust community on other programming languages will have good and
meaningful cybersecurity enhancements for developers who may never have a desire to learn Rust.
The programming landscape is changing. Just as Chrome OS wouldn’t exist without Gentoo Linux,
the same can be said about many of the upcoming C++26 proposals inspired by Rust programming
paradigms.
</p>
<!-- l. 80 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   I cannot say enough good things about Rust, Ada, and other memory-safe programming languages; however,
that praise should be tempered with the realization that these languages are not the silver bullet of memory safety
to mandate at an organizational level. Doing so will cause leadership to develop a false sense of security that will be
dangerous in the long run.
                                                                                         
                                                                                         
</p>
   

<h3 class="sectionHead" style="line-height: 1.2; font-size: 1.5157em;"><a id="x1-5000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>References</h3>


<!-- l. 52 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">    
</p>


<dl class="thebibliography"><dt class="thebibliography" id="X0-20250512_hood" style="float: left; clear: left; margin-right: 1em;">
[1]  
</dt><dd class="thebibliography" id="bib-1" style="margin-left: 2.5em;">
<!-- l. 52 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0_20250512_hood" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon     Hood.     “Ada     Unchecked     Conversions”.     In:     <span class="uline" style="text-decoration: underline;">SwATips.com</span>     (2023).     <span class="small-caps" style="font-variant: small-caps;">url</span>:     
<a class="url" href="https://www.swatips.com/articles/20230410.html" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.swatips.com/articles/20230410.html</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-20250512_hood2" style="float: left; clear: left; margin-right: 1em;">
[2]  
</dt><dd class="thebibliography" id="bib-2" style="margin-left: 2.5em;">
<!-- l. 52 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0_20250512_hood2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon Hood. “Back to the Building Blocks: Codifying Complacency”. In: <span class="uline" style="text-decoration: underline;">SwATips.com</span> (2024). <span class="small-caps" style="font-variant: small-caps;">url</span>: 
<a class="url" href="https://www.swatips.com/articles/20240902.html" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.swatips.com/articles/20240902.html</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-swatips" style="float: left; clear: left; margin-right: 1em;">
[3]  
</dt><dd class="thebibliography" id="bib-3" style="margin-left: 2.5em;">
<!-- l. 52 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0_swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon Hood, ed. <span class="uline" style="text-decoration: underline;">SwATips</span>. <a class="url" href="https://www.SwATips.com/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.SwATips.com/</span></a>.</p></dd></dl>

 

]]></description>
	</item>
	<item>
		<title>Defensive Development Plans</title>
		<link>https://www.SwATips.com/articles/20250127.html</link>
		<pubDate>Mon, 27 Jan 2025 00:00:00 -0600</pubDate>
<description><![CDATA[

<p style="margin-top: 0; margin-bottom: 0;"><a href="/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/swatips.svg" width="120" alt="SwATips" style="border-top: 0; border-left: 0; border-right: 0;"/></a>| <a href="articles/20250127.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">pdf</a> | <a rel="license" href="http://creativecommons.org/licenses/by/4.0/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/by.svg" width="60" height="21" alt="CC-BY" style="border-top: 0; border-left: 0; border-right: 0;"/></a></p>


<div class="maketitle" style="margin-top: 1em; text-align: center; margin-bottom: 2em;">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead" style="line-height: 1.2; text-align: center;"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a id="x1-3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1</a>]<br/>
</h2>
 <div class="author" style="text-align: center;"><span class="ec-lmr-12" style="font-size: 120%;">Jon Hood</span></div><br/>
<div class="date" style="text-align: center;"><span class="ec-lmr-12" style="font-size: 120%;">Monday 27</span><sup class="textsuperscript"><span class="ec-lmr-9" style="font-size: 90%;">th</span></sup><span class="ec-lmr-12" style="font-size: 120%;"> January, 2025</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead" style="line-height: 1.2; font-size: 1.5157em;"><span class="titlemark">1   </span> <a id="x1-10001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Defensive Development Plans</h3>


<!-- l. 46 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;"><span class="ec-lmr-8" style="font-size: 80%;">Updated Saturday 25</span><sup class="textsuperscript"><span class="ec-lmr-9" style="font-size: 90%;">th</span></sup><span class="ec-lmr-8" style="font-size: 80%;"> January, 2025</span>
</p>
<!-- l. 1 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   A Software Development Plan should be well-structured and implement secure principles for the lifecycle of a
software product. The plan should be rigid in the areas of security while remaining flexible to changing
threats and discoveries. When security needs change, a robust change management board can make sure
that the changes do not impact the security of the overall architecture. Suppose that an overzealous
developer, eager to eke out the greatest performance of their software, decides to include the compiler flag
<span class="ec-lmtt-10" style="font-family: monospace,monospace;">-fno-stack-protector </span>while building the software. This article will walk through the examples of a sound,
consistent Software Assurance implementation which protects against such issues using a defense-in-depth
perspective.
</p>
<!-- l. 3 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="likesubsectionHead" style="line-height: 1.2; font-size: 1.3195em;"><a id="x1-2000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>An Example Issue</h4>


<!-- l. 4 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Suppose that we are given the example code in Listing <a href="#x1-2001r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1<!-- tex4ht:ref: lst:20250127:overflow  --></a>. This code will be used to show the breadth of areas where
the issue can escalate in security impact and examine how each layer of Software Assurance can identify
it.
</p>
   

<!-- l. 6 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-2001r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>
<a id="x1-2002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>   
</p>
<pre class="lstlisting" id="listing-1" style="font-family: monospace,monospace; white-space: pre-wrap; margin-top: 0.5em; margin-bottom: 0.5em; background-color: #BFBFBF;"><span class="label" style="margin-right: 0.5em;"><a id="x1-2003r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">#</span></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">include</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">&lt;stdio.h&gt;</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-2004r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">#</span></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">include</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">&lt;stdlib.h&gt;</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-2005r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">#</span></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">include</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">&lt;string.h&gt;</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-2006r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">void</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">vulnF(</span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">char </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">*input) {</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-2007r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">    </span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">char</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">buffer[32];</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-2008r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">    </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">strcpy</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">(</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">buffer</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">,</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">input);</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-2009r7" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">    </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">printf</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">(</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">"</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">Input</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">copied: %s\n", buffer);</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-2010r8" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">}</span></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-2011r9" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">int</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">main() {</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-2012r10" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">    </span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">char</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">toCopy[100];</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-2013r11" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">    </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">printf</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">(</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">"</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">Enter</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">input: ");</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-2014r12" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">    </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">fgets</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">(</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">toCopy</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">,</span></span><span style="color:#000000"> <span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">sizeof</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">(toCopy), stdin);</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-2015r13" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">    </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">vulnF</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">(</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">toCopy</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">);</span></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-2016r14" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">    </span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">return</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">0;</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-2017r15" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">}</span></span></pre>


<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 1: </span><span class="content">User Input Buffer Overflow</span></figcaption>
<!-- tex4ht:label?: x1-2017r  -->


<!-- l. 24 -->
<p class="indent" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   This example is compiled with the <span class="ec-lmtt-10" style="font-family: monospace,monospace;">-fno-stack-protector </span>flag. It represents a basic string copy
overflow.
</p>
<!-- l. 26 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="likesubsectionHead" style="line-height: 1.2; font-size: 1.3195em;"><a id="x1-3000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>SA-11(1): Static Code Analysis</h4>


<!-- l. 27 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Most static analysis tools would be able to identify the issue in the code. Making sure that Static Application
Security Testing (SAST) is enabled and enforcing is a good, easy first-line of defense. Using the static code analysis
tool <span class="ec-lmtt-10" style="font-family: monospace,monospace;">infer</span>, the issue is detected in Listing <a href="#x1-3001r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2<!-- tex4ht:ref: lst:20250127:sast  --></a>.
</p>
   

<!-- l. 29 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-3001r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>
<a id="x1-3002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>   
</p>
<pre class="lstlisting" id="listing-2" style="font-family: monospace,monospace; white-space: pre-wrap; margin-top: 0.5em; margin-bottom: 0.5em; background-color: #BFBFBF;"><span class="label" style="margin-right: 0.5em;"><a id="x1-3003r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">$</span></span><span style="color:#000000"> <span class="ec-lmtt-10" style="font-family: monospace,monospace;">infer -P --bufferoverrun analyze --</span></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> </span><span style="color:#000000"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">gcc</span></span><span style="color:#000000"> <span class="ec-lmtt-10" style="font-family: monospace,monospace;">-c </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">test</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">.c</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3004r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10" style="font-family: monospace,monospace;">test</span></span><span style="color:#000000"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">.</span></span><span style="color:#000000"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">c</span></span><span style="color:#000000"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">:13:</span></span><span style="color:#000000"> <span class="ec-lmtt-10" style="font-family: monospace,monospace;">error: Buffer Overrun L2</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3005r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">  </span><span style="color:#000000"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">Offset</span></span><span style="color:#000000"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">:</span></span><span style="color:#000000"> <span class="ec-lmtt-10" style="font-family: monospace,monospace;">[0, 99] Size: 32 by call to </span><span class="ts1-lmtt10-">`</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">vulnF</span><span class="ts1-lmtt10-">`</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">.</span></span></pre>


<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 2: </span><span class="content">SAST Detection of Buffer Overrun</span></figcaption>
<!-- tex4ht:label?: x1-3005r  -->


<!-- l. 35 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">
</p>
   

<h4 class="likesubsectionHead" style="line-height: 1.2; font-size: 1.3195em;"><a id="x1-4000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>SA-11(4): Manual Code Reviews</h4>


<!-- l. 36 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Manual code reviews, peer reviews, peer programming, and acceptance reviews of code changes create a sense of
accountability where developers learn from each other.
                                                                                         
                                                                                         
</p>
<!-- l. 38 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="likesubsectionHead" style="line-height: 1.2; font-size: 1.3195em;"><a id="x1-5000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>SA-11(5): Penetration Testing</h4>


<!-- l. 39 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Pentesting events should include the software below the system level. A robust pentest event will make sure that the
binaries installed on the system under test have proper protections enabled. In the case of this binary, the stack
smashing canaries (which get overridden for detecting an overflow) are missing, letting the pentest team know that
defense-in-depth protection is missing from it. Listing <a href="#x1-5001r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">3<!-- tex4ht:ref: lst:20250127:pentest  --></a> shows a snippet of one pentesting tool which identifies the
missing stack protections.
</p>
   

<!-- l. 41 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-5001r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>
<a id="x1-5002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>   
</p>
<pre class="lstlisting" id="listing-3" style="font-family: monospace,monospace; white-space: pre-wrap; margin-top: 0.5em; margin-bottom: 0.5em; background-color: #BFBFBF;"><span class="label" style="margin-right: 0.5em;"><a id="x1-5003r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">$</span></span><span style="color:#000000"> <span class="ec-lmtt-10" style="font-family: monospace,monospace;">checksec --file=</span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">test</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-5004r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">STACK</span></span><span style="color:#000000"> <span class="ec-lmtt-10" style="font-family: monospace,monospace;">CANARY</span> </span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">    </span><span style="color:#000000"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">NX</span></span><span style="color:#000000"> </span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">          </span><span style="color:#000000"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">PIE</span></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-5005r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">No</span></span><span style="color:#000000"> <span class="ec-lmtt-10" style="font-family: monospace,monospace;">canary found</span> </span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">  </span><span style="color:#000000"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">NX</span></span><span style="color:#000000"> <span class="ec-lmtt-10" style="font-family: monospace,monospace;">enabled</span> </span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">   </span><span style="color:#000000"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">PIE</span></span><span style="color:#000000"> <span class="ec-lmtt-10" style="font-family: monospace,monospace;">enabled</span></span></pre>


<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 3: </span><span class="content">Pentest Detection of Stack Protection</span></figcaption>
<!-- tex4ht:label?: x1-5005r  -->


<!-- l. 47 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">
</p>
   

<h4 class="likesubsectionHead" style="line-height: 1.2; font-size: 1.3195em;"><a id="x1-6000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>SA-11(8): Dynamic Code Analysis</h4>


<!-- l. 48 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Several dynamic analysis techniques are able to identify the issue. Debugging and dynamic execution with
sufficiently large input results in detection of the issue as shown in Listing <a href="#x1-6001r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">4<!-- tex4ht:ref: lst:20250127:dynamic  --></a> using Memcheck with Valgrind.
Instrumenting the binary and fuzzing the application is also a form of dynamic analysis, where a good and a bad
seed input are run quickly by AFL in Listing <a href="#x1-6008r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">5<!-- tex4ht:ref: lst:20250127:fuzz  --></a>.
</p>
   

<!-- l. 50 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-6001r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>
<a id="x1-6002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>   
</p>
<pre class="lstlisting" id="listing-4" style="font-family: monospace,monospace; white-space: pre-wrap; margin-top: 0.5em; margin-bottom: 0.5em; background-color: #BFBFBF;"><span class="label" style="margin-right: 0.5em;"><a id="x1-6003r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">$</span></span><span style="color:#000000"> <span class="ec-lmtt-10" style="font-family: monospace,monospace;">valgrind --leak-check=yes ./</span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">test</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-6004r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">==43968==</span></span><span style="color:#000000"> <span class="ec-lmtt-10" style="font-family: monospace,monospace;">Memcheck, a memory error detector</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-6005r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">Enter</span></span><span style="color:#000000"> <span class="ec-lmtt-10" style="font-family: monospace,monospace;">input: aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-6006r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">Input</span></span><span style="color:#000000"> <span class="ec-lmtt-10" style="font-family: monospace,monospace;">copied: aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-6007r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">==43968==</span></span><span style="color:#000000"> <span class="ec-lmtt-10" style="font-family: monospace,monospace;">Jump to the invalid address stated on the next line</span></span></pre>


<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 4: </span><span class="content">Valgrind Detection of Memory Overlap</span></figcaption>
<!-- tex4ht:label?: x1-6007r  -->

   

<!-- l. 58 -->


<p style="margin-top: 0; margin-bottom: 0;"><a id="x1-6008r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>
<a id="x1-6009" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>   
</p>
<pre class="lstlisting" id="listing-5" style="font-family: monospace,monospace; white-space: pre-wrap; margin-top: 0.5em; margin-bottom: 0.5em; background-color: #BFBFBF;"><span class="label" style="margin-right: 0.5em;"><a id="x1-6010r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">$</span></span><span style="color:#000000"> <span class="ec-lmtt-10" style="font-family: monospace,monospace;">AFL_USE_ASAN=1 afl-clang-fast </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">test</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">.c -o </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">test</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-6011r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">[+]</span></span><span style="color:#000000"> <span class="ec-lmtt-10" style="font-family: monospace,monospace;">Instrumented 2 locations with no collisions (non-hardened, ASAN mode)</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-6012r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">of</span></span><span style="color:#000000"> <span class="ec-lmtt-10" style="font-family: monospace,monospace;">which are 0 handled and 0 unhandled selects.</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-6013r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">$</span></span><span style="color:#000000"> <span class="ec-lmtt-10" style="font-family: monospace,monospace;">afl-fuzz -i </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">in </span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">-o out --</span></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> </span><span style="color:#000000"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">./</span></span><span style="color:#000000"><span class="ec-lmtk-10" style="font-family: monospace,monospace;">test</span></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-6014r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">cycles</span></span><span style="color:#000000"> <span class="ec-lmtk-10" style="font-family: monospace,monospace;">done </span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">: 2</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-6015r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">corpus</span></span><span style="color:#000000"> <span class="ec-lmtt-10" style="font-family: monospace,monospace;">count : 2</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-6016r7" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">saved</span></span><span style="color:#000000"> <span class="ec-lmtt-10" style="font-family: monospace,monospace;">crashes : 1</span></span></pre>


<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 5: </span><span class="content">Fuzzing for Crashes</span></figcaption>
<!-- tex4ht:label?: x1-6016r  -->


<!-- l. 68 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">
</p>
   

<h4 class="likesubsectionHead" style="line-height: 1.2; font-size: 1.3195em;"><a id="x1-7000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>SA-15: Development Process, Standards, and Tools</h4>


<!-- l. 69 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">The tools, explicitly including the <strong>tool options and tool configurations</strong>, must be documented. This includes the
compiler and pipeline options used to build production-like binaries. The documentation of permitted tool options
allows oversight and visibility into how the products coming out of a pipeline are built. Requiring the
documentation of which tools and options are used will help prevent deviations from safe and approved options.
A good example for the software development plan, configuration option documentation, or supply
chain risk management plan would be, “The production software is built with GCC version 14.2 using
compiler flags <span class="ec-lmtt-10" style="font-family: monospace,monospace;">-Os -march=corei7 -pipe -Wall -Werror </span>for the x86_64 architecture using Oracle Linux
9.”
                                                                                         
                                                                                         
</p>
<!-- l. 71 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   When someone adds in potentially unsafe flags like <span class="ec-lmtt-10" style="font-family: monospace,monospace;">-fno-stack-protector</span>, <span class="ec-lmtt-10" style="font-family: monospace,monospace;">-fpermissive</span>, <span class="ec-lmtt-10" style="font-family: monospace,monospace;">-gnatp</span>, <span class="ec-lmtt-10" style="font-family: monospace,monospace;">-fno-pie</span>,
<span class="ec-lmtt-10" style="font-family: monospace,monospace;">-fno-pic</span>, <span class="ec-lmtt-10" style="font-family: monospace,monospace;">-fno-strict-aliasing</span>, or even compiling the production library with debug symbols (<span class="ec-lmtt-10" style="font-family: monospace,monospace;">-g</span>), this
deviates from the whitelist of permitted flags. Even changing memory alignment (<span class="ec-lmtt-10" style="font-family: monospace,monospace;">-fpack-struct</span>) or
changing the math calculation precision (<span class="ec-lmtt-10" style="font-family: monospace,monospace;">-ffast-math</span>) can cause serious and detrimental issues to a
program.
</p>
<!-- l. 73 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   There are new compiler flags coming out frequently, and sticking to a whitelist of permitted flags,
allowing them to change only with proper change management processes, is the best way to prevent
potentially dangerous ones from getting in and being extremely difficult to find. This leads to an important
requirement in Software Assurance: having someone who understands security on the change control
board. This person should be able to understand architectural issues as changes come in to support
more than just the Intel Core i7 processor, as in the aforementioned example. Flags affecting integral
endianness (<span class="ec-lmtt-10" style="font-family: monospace,monospace;">-mbig-endian</span>), structure packing (<span class="ec-lmtt-10" style="font-family: monospace,monospace;">-fpack-struct</span>), floating point precision alignment
(<span class="ec-lmtt-10" style="font-family: monospace,monospace;">-malign-double</span>), and processor extensions (<span class="ec-lmtt-10" style="font-family: monospace,monospace;">-msse</span>) may not have immediate security concerns until they affect the
portability of the code. Having a dedicated security specialist watching for these types of issues during the
architecture and design of application changes helps prevent issues from making it into the supply
chain.
</p>
<!-- l. 75 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="likesubsectionHead" style="line-height: 1.2; font-size: 1.3195em;"><a id="x1-8000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>SA-16: Developer-Provided Training</h4>


<!-- l. 76 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Having standards and practices is important, but making sure the developers are trained to abide by those
standards brings a level of depth and ownership to issues as they are encountered.
</p>
<!-- l. 78 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="likesubsectionHead" style="line-height: 1.2; font-size: 1.3195em;"><a id="x1-9000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>SA-17(3) and SA-17(4): Correspondence</h4>


<!-- l. 79 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">The Application Security and Development Security Technical Implementation Guide (STIG) maps the requirement
to have a secure coding standard to CCI-3323 which falls under RMF control SA-17(4). Note that the primary
concern for STIGs isn’t functionality coding standards, such as the JTA-Army, ADA compliance, and
Internationalization standards: the cybersecurity coding standards are the secure coding standards referenced here.
The program should implement secure coding standards, like the CERT standards which specify many rules that are
violated in our example (such as MEM35-C and STR31-C). Establishing a set of coding standards would
forbid this type of code from being created, particularly when combined with the developer training
programs.
</p>
<!-- l. 81 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="likesubsectionHead" style="line-height: 1.2; font-size: 1.3195em;"><a id="x1-10000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>SR-9: Tamper Resistance and Detection</h4>


<!-- l. 82 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Application whitelisting, binary signing, source fortification (<span class="ec-lmtt-10" style="font-family: monospace,monospace;">-D_FORTIFY_SOURCE</span>), control flow fortification
(<span class="ec-lmtt-10" style="font-family: monospace,monospace;">-fcf-protection</span>), position-independent executables and libraries (<span class="ec-lmtt-10" style="font-family: monospace,monospace;">-fPIE </span>and <span class="ec-lmtt-10" style="font-family: monospace,monospace;">-fPIC</span>), non-executable stacks
(<span class="ec-lmtt-10" style="font-family: monospace,monospace;">-z,noexecstack</span>), stronger stack protection canaries (<span class="ec-lmtt-10" style="font-family: monospace,monospace;">-fstack-protector-strong </span>and <span class="ec-lmtt-10" style="font-family: monospace,monospace;">-fstack-protector-all</span>),
and many other techniques for preventing a secured, approved binary from being tampered with can be enacted.
When a binary deviates from what is expected, it should be detected.
</p>
<!-- l. 84 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Though easy to tamper with, doing extra, unexpected, additional verification can be useful. Compiling a binary
with <span class="ec-lmtt-10" style="font-family: monospace,monospace;">-frecord-gcc-switches </span>will store the compiler flags used by GCC in a comment inside the binary; including
a manual check to make sure that this comment is consistent with the development plan’s permitted flags provides
an extra level of defense-in-depth verification at the cost of exposing how the binary is built to potential attackers if
it is not stripped out prior to delivery.
                                                                                         
                                                                                         
</p>
<!-- l. 86 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="likesubsectionHead" style="line-height: 1.2; font-size: 1.3195em;"><a id="x1-11000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Conclusion</h4>


<!-- l. 87 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">There are many areas where issues caused by an errant compiler flag, and even the errant flags themselves, can be
detected. No single point of failure is to blame when supply chain compromises sneak their way into production.
Testing the detection mechanisms that are in place with blue team events and cooperative vulnerability assessments
can build confidence that more pernicious errors don’t manifest in the final product. Bringing the compiler versions,
flags, configurations, and options under control of the change management board in RMF control SA-15 can be
accomplished in many different ways, and a complete software development plan will document policies for its
enforcement.
                                                                                         
                                                                                         
</p>
   

<h3 class="sectionHead" style="line-height: 1.2; font-size: 1.5157em;"><a id="x1-12000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>References</h3>


<!-- l. 51 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">    
</p>


<dl class="thebibliography"><dt class="thebibliography" id="X0-swatips" style="float: left; clear: left; margin-right: 1em;">
[1]  
</dt><dd class="thebibliography" id="bib-1" style="margin-left: 2.5em;">
<!-- l. 51 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon Hood, ed. <span class="uline" style="text-decoration: underline;">SwATips</span>. <a class="url" href="https://www.SwATips.com/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.SwATips.com/</span></a>.</p></dd></dl>

 

]]></description>
	</item>
	<item>
		<title>Fuzzy Coverage</title>
		<link>https://www.SwATips.com/articles/20241118.html</link>
		<pubDate>Mon, 18 Nov 2024 00:00:00 -0600</pubDate>
<description><![CDATA[

<p style="margin-top: 0; margin-bottom: 0;"><a href="/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/swatips.svg" width="120" alt="SwATips" style="border-top: 0; border-left: 0; border-right: 0;"/></a>| <a href="articles/20241118.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">pdf</a> | <a rel="license" href="http://creativecommons.org/licenses/by/4.0/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/by.svg" width="60" height="21" alt="CC-BY" style="border-top: 0; border-left: 0; border-right: 0;"/></a></p>


<div class="maketitle" style="margin-top: 1em; text-align: center; margin-bottom: 2em;">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead" style="line-height: 1.2; text-align: center;"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a id="x1-3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0_swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1</a>]<br/>
</h2>
 <div class="author" style="text-align: center;"><span class="ec-lmr-12" style="font-size: 120%;">Jon Hood</span></div><br/>
<div class="date" style="text-align: center;"><span class="ec-lmr-12" style="font-size: 120%;">Monday 18</span><sup class="textsuperscript"><span class="ec-lmr-9" style="font-size: 90%;">th</span></sup><span class="ec-lmr-12" style="font-size: 120%;"> November, 2024</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead" style="line-height: 1.2; font-size: 1.5157em;"><span class="titlemark">1   </span> <a id="x1-10001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Fuzzy Coverage</h3>


<!-- l. 45 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;"><span class="ec-lmr-8" style="font-size: 80%;">Updated Monday 18</span><sup class="textsuperscript"><span class="ec-lmr-9" style="font-size: 90%;">th</span></sup><span class="ec-lmr-8" style="font-size: 80%;"> November, 2024</span>
</p>
<!-- l. 1 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   One of the questions we get asked frequently is, “How much fuzzing is enough?” This question is usually
derived from a DoD mentality of checking the box on cybersecurity activities. With Security Technical
Implementation Guides (STIGs), IAVMs, and RMF Control checklists, cybersecurity practitioners
can become complacent switching from a compliance checkbox mindset to a true risk management
mindset.
</p>
<!-- l. 3 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Fuzzing is one of the dynamic code analysis tasks permitted in Risk Management Framework (RMF) control
SA-11(8). “Fuzz testing strategies are derived from the intended use of applications and the functional and design
specifications for the applications.”[<a id="x1-1001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0_20241118_nist80053rev5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">3</a>, p. 279] While fuzzing is <i>derived</i> from functional test cases (such as unit
testing or formal qualification testing cases), fuzz testing enters into the security domain by executing varying inputs
into functionality test cases. These generated, often mutating inputs are used to identify security-critical bugs and
defects in the software. “More generally, fuzzing is used to demonstrate the presence of bugs rather than their
absence.”[<a id="x1-1002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0_20241118_wikifuzzing" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">4</a>] Popular sanitizers for fuzzing include memory related issues (CWE-118 and its children such as buffer
overflows CWE-120, out-of-bounds access CWE-125 and CWE-787, overflows CWE-190, and more), race
conditions (CWE-362), undefined behavior (CWE-758), and control flow integrity (CWE-691). By
providing a hook into an application with a fuzzing harness and given an expected input, a fuzzer can
iterate over unexpected and untested inputs rapidly to find cybersecurity issues which may lead to
compromise.
</p>
<!-- l. 5 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Notice how fuzzing is intended to prove a negative: a failed test case indicates a high likelihood that the code
has an error. This introduces the first misconception of fuzzing. The reverse is not necessitated: <strong>the
lack of findings from fuzzing does not indicate the absence of defects.</strong> Using fuzz testing as
evidence for the lack of cybersecurity defects in software is not one of the main goals for implementing a
fuzzing program. When setting up a Software Assurance program, results from fuzz testing should
be given very low assurance when it is used as the input to prove that an application is free from
defects.
</p>
<!-- l. 7 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   The idea that fuzz testing is a checkbox to complete directly feeds into the second mistake of fuzzing: <strong>declaring
that any amount of fuzzing is enough</strong>. This is most evident when someone asks, “Did you fuzz the
application?” The correct question is, “How much of the application are you fuzzing?” Always be fuzzing. And if it
has been a while since the test cases have found anything, consider updating the harnesses to execute tests
differently.
</p>
<!-- l. 9 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Finally, most metrics for fuzz testing in the DoD declare a code coverage percentage that is required for the test
harnesses. But <strong>code coverage is not a meaningful metric for fuzz test completion.</strong> Consider the example in
Listing <a href="#x1-1003r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1<!-- tex4ht:ref: lst:20241118:overflow  --></a>. If this code were to be harnessed and passed an input of <span class="ec-lmtt-10" style="font-family: monospace,monospace;">Jon</span>, then 100% of the code is executed but the
buffer overflow condition is not detected. Stopping the fuzzing activity when a percentage of code branches are
completed or when <span class="ec-lmtt-10" style="font-family: monospace,monospace;">lcov </span>or <span class="ec-lmtt-10" style="font-family: monospace,monospace;">gcov </span>return that a certain percentage of the code paths have been executed creates a
false sense of security.
</p>
   

<!-- l. 11 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-1003r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>
<a id="x1-1004" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>   
</p>
<pre class="lstlisting" id="listing-1" style="font-family: monospace,monospace; white-space: pre-wrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-1005r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">#</span></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">include</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">&lt;stdio.h&gt;</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-1006r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">#</span></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">include</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">&lt;string.h&gt;</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-1007r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">int</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">main() {</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-1008r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">    </span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">char</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">buffer[10];</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-1009r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">    </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">printf</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">(</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">"</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">Enter</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">your name: ");</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-1010r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">    </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">fgets</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">(</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">buffer</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">,</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">100, stdin);</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-1011r7" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">    </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">printf</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">(</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">"</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">Hello</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">,</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">%s!\n", buffer);</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-1012r8" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">    </span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">return</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">0;</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-1013r9" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">}</span></span></pre>


<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 1: </span><span class="content">Simple Buffer Overflow</span></figcaption>
<!-- tex4ht:label?: x1-1013r1  -->


<!-- l. 23 -->
<p class="indent" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   Instead, experts should review the harnesses to make sure that the critical areas of code are properly being
fuzzed continuously. One way to complete this is to do a criticality analysis and functional traceability report into
the code, such as the design traceability analysis[<a id="x1-1014" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0_20241118_ieee1012" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2</a>, p. 114] and source code traceability analysis[<a href="#cite.0_20241118_ieee1012" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2</a>, p. 119].
Leveraging these functionality reviews to define whether the critical parts of the code have been harnessed allows a
DoD program office to say, “Yea, verily, the fuzzing being conducted by this effort satisfies our fuzzing
requirements.”
                                                                                         
                                                                                         
</p>
<!-- l. 25 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="likesubsectionHead" style="line-height: 1.2; font-size: 1.3195em;"><a id="x1-2000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Summary</h4>


<!-- l. 26 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Remember the misconceptions of fuzzing: </p>


<ul class="itemize1">     
<li class="itemize">The lack of findings from fuzzing does not indicate the absence of defects.
</li>
<li class="itemize">No amount of fuzzing is “enough.”
</li>
<li class="itemize">Code coverage is not a meaningful metric for fuzz test completion.</li></ul>


<!-- l. 33 -->
<p class="indent" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   The right fuzzing program is the one still running against critically important code.
                                                                                         
                                                                                         
</p>
   

<h3 class="sectionHead" style="line-height: 1.2; font-size: 1.5157em;"><a id="x1-3000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>References</h3>


<!-- l. 50 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">    
</p>


<dl class="thebibliography"><dt class="thebibliography" id="X0-swatips" style="float: left; clear: left; margin-right: 1em;">
[1]  
</dt><dd class="thebibliography" id="bib-1" style="margin-left: 2.5em;">
<!-- l. 50 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0_swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon Hood, ed. <span class="uline" style="text-decoration: underline;">SwATips</span>. <a class="url" href="https://www.SwATips.com/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.SwATips.com/</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-20241118_ieee1012" style="float: left; clear: left; margin-right: 1em;">
[2]  
</dt><dd class="thebibliography" id="bib-2" style="margin-left: 2.5em;">
<!-- l. 50 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0_20241118_ieee1012" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>IEEE Standards Association. “IEEE Standard for System, Software, and Hardware Verification and
Validation”.  In:  <span class="uline" style="text-decoration: underline;">IEEE  Std  1012-2016  (Revision  of  IEEE  Std  1012-2012/  Incorporates  IEEE  Std
1012-2016/Cor1-2017)</span> (2017), pp. 1–260. <span class="small-caps" style="font-variant: small-caps;">doi</span>:  <a href="https://doi.org/10.1109/IEEESTD.2017.8055462" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">10.1109/IEEESTD.2017.8055462</a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-20241118_nist80053rev5" style="float: left; clear: left; margin-right: 1em;">
[3]  
</dt><dd class="thebibliography" id="bib-3" style="margin-left: 2.5em;">
<!-- l. 50 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0_20241118_nist80053rev5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>National Institute of Standards and Technology. <span class="uline" style="text-decoration: underline;">Security and Privacy Controls for Information Systems
and         Organizations</span>.         Tech.         rep.         Special         Publication         (SP)         800-53
Revision 5. Washington, D.C.: U.S. Department of Commerce, 2020. <span class="small-caps" style="font-variant: small-caps;">doi</span>:  <a href="https://doi.org/10.6028/NIST.SP.800-53r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">10.6028/NIST.SP.800-53r5</a>.
<span class="small-caps" style="font-variant: small-caps;">url</span>: <a class="url" href="https://nvlpubs.nist.gov/nistpubs/SpecialPublications/NIST.SP.800-53r5.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://nvlpubs.nist.gov/nistpubs/SpecialPublications/NIST.SP.800-53r5.pdf</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-20241118_wikifuzzing" style="float: left; clear: left; margin-right: 1em;">
[4]  
</dt><dd class="thebibliography" id="bib-4" style="margin-left: 2.5em;">
<!-- l. 50 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0_20241118_wikifuzzing" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Wikipedia
contributors. <span class="uline" style="text-decoration: underline;">Fuzzing — Wikipedia, The Free Encyclopedia</span>. [Online; accessed 18-November-2024]. 2024.
<span class="small-caps" style="font-variant: small-caps;">url</span>: <a class="url" href="https://en.wikipedia.org/w/index.php?title=Fuzzing&amp;oldid=1249540069" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://en.wikipedia.org/w/index.php?title=Fuzzing&amp;oldid=1249540069</span></a>.</p></dd></dl>

 

]]></description>
	</item>
	<item>
		<title>Back to the Building Blocks: Codifying Complacency</title>
		<link>https://www.SwATips.com/articles/20240902.html</link>
		<pubDate>Mon, 02 Sep 2024 00:00:00 -0500</pubDate>
<description><![CDATA[

<p style="margin-top: 0; margin-bottom: 0;"><a href="/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/swatips.svg" width="120" alt="SwATips" style="border-top: 0; border-left: 0; border-right: 0;"/></a>| <a href="articles/20240902.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">pdf</a> | <a rel="license" href="http://creativecommons.org/licenses/by/4.0/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/by.svg" width="60" height="21" alt="CC-BY" style="border-top: 0; border-left: 0; border-right: 0;"/></a></p>


<div class="maketitle" style="margin-top: 1em; text-align: center; margin-bottom: 2em;">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead" style="line-height: 1.2; text-align: center;"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a id="x1-3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">4</a>]<br/>
</h2>
<div class="author" style="text-align: center;"><span class="ec-lmr-12" style="font-size: 120%;">Jon Hood</span></div><br/>
<div class="date" style="text-align: center;"><span class="ec-lmr-12" style="font-size: 120%;">Monday 2</span><sup class="textsuperscript"><span class="ec-lmr-9" style="font-size: 90%;">nd</span></sup><span class="ec-lmr-12" style="font-size: 120%;"> September, 2024</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead" id="back-to-the-building-blocks-codifying-complacency" style="line-height: 1.2; font-size: 1.5157em;"><span class="titlemark">1   </span> <a id="x1-10001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Back to the Building Blocks: Codifying Complacency</h3>


<!-- l. 45 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;"><span class="ec-lmr-8" style="font-size: 80%;">Updated Wednesday 28</span><sup class="textsuperscript"><span class="ec-lmr-9" style="font-size: 90%;">th</span></sup><span class="ec-lmr-8" style="font-size: 80%;"> August, 2024</span>
</p>
<!-- l. 1 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   In February, the National Cyber Director, Harry Coker, presented the White House’s strategy for combating
cyber threats. Included in this strategy, the White House instructed technical practitioners to heed reports such as
<i>Back to the Building Blocks: A Path Toward Secure and Measurable Software</i>.[<a id="x1-1001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@20240902:coker" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1</a>]
</p>
<!-- l. 3 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   A core piece of the White House’s strategy is to “eliminate entire categories of software vulnerabilities” by using
programming languages which do not “lack traits associated with memory safety.”[<a id="x1-1002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@20240902:whitehouse" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">5</a>, p. 7] While the White House
should be applauded for recognizing the pervasive nature of memory safety vulnerabilities, there is an
underlying flaw in the assertations of the recommendation. The report continues, “C and C++…are not
memory safe programming languages. Rust [is] one example of a memory safe programming language…”[<a href="#cite.0@20240902:whitehouse" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">5</a>,
p. 9]
</p>
<!-- l. 5 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   As a software assurance practitioner, I get to review a large amount of “memory-safe” Ada software and some
Rust applications. To date, only a single project that has been provided to me for review written in either of
these languages use only the memory safe features of the language. Over 99% of the projects I have
reviewed either use <span class="ec-lmtt-10" style="font-family: monospace,monospace;">unchecked_conversions </span>in Ada[<a id="x1-1003" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@20240902:hood" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2</a>] or raw pointers in Rust. Frequently, these projects
also disable the additional memory safety checks explicitly while citing real-time and performance
requirements. Contrast this to software written in C++ where it is not unusual to receive a project with
enforced coding standards. Some of these coding standards can require developers to use smart pointers,
RAII concepts, and memory-safe development practices. A C++ program written with such enforced
coding standards will undoubtedly have fewer memory vulnerabilities than a Rust program using raw
pointers.
</p>
<!-- l. 7 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   A development organization shouldn’t rely on the White House’s misguided recommendations to use Rust
instead of C++. There are certainly unique Rust features that afford memory safe programming design for
developers. To program in Rust, a developer is required to understand its concepts of ownership. Its ownership
system allows the compiler to make memory safety guarantees and enables the borrow checker. While modern C++
compilers have made large improvements to verifying lifetime ownership (such as Clang’s -Wlifetime warnings), and
several borrow checking implementations for C++ exist, very few projects use those features. Rust, however, was
engineered around the borrow checker.
</p>
<!-- l. 9 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   In conclusion, the White House did a tremendous disservice to the development community by not
recommending the enforcement of RAII concepts[<a id="x1-1004" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@20240902:hood2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">3</a>], smart pointers, and secure coding standards. Software
assurance practitioners should be prepared to evaluate Rust and other “memory safe” software applications with an
additional level of scrutiny in verifying that the memory safety protections have not been bypassed.
Furthermore, DoD project offices have a history of ignoring memory safety issues when software is written
in a language such as Ada or Rust, citing misguided directions like this one from the White House.
When we deliver a report with identified memory overflows, the project office’s reflex is frequently to
ignore the issue. Project offices could become complacent, and the issues may be swept under the
rug.
</p>
<!-- l. 11 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   In a worst-case scenario, thirty years from now, some software assurance team is going to get a critical,
Rust-developed application riddled with assembly and raw pointer memory vulnerabilities. They will ask why the
project office did not heed the software assurance scans conducted decades earlier. The project office will answer,
“We were told this was a safe language and that we weren’t vulnerable to those issues,”–the same
excuse we receive from project offices with legacy Ada code today. Hopefully, these project offices
implement the additional memory safe hardware and formal method recommendations from the White
House.
                                                                                         
                                                                                         
</p>
   

<h3 class="sectionHead" id="references" style="line-height: 1.2; font-size: 1.5157em;"><a id="x1-2000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>References</h3>


<!-- l. 50 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">    
</p>


<dl class="thebibliography"><dt class="thebibliography" id="X0-20240902:coker" style="float: left; clear: left; margin-right: 1em;">
[1]  
</dt><dd class="thebibliography" id="bib-1" style="margin-left: 2.5em;">
<!-- l. 50 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20240902:coker" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Harry   Coker.   <span class="uline" style="text-decoration: underline;">National   Cyber   Director   and   Assistant   Director</span>.   White   House.   2024.   <span class="small-caps" style="font-variant: small-caps;">url</span>:   
<a class="url" href="https://youtu.be/xVYSvkogoUM?si=7i5_GbuShOJ4ShCt&amp;t=259" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://youtu.be/xVYSvkogoUM?si=7i5_GbuShOJ4ShCt&amp;t=259</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-20240902:hood" style="float: left; clear: left; margin-right: 1em;">
[2]  
</dt><dd class="thebibliography" id="bib-2" style="margin-left: 2.5em;">
<!-- l. 50 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20240902:hood" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon     Hood.     “Ada     Unchecked     Conversions”.     In:     <span class="uline" style="text-decoration: underline;">SwATips.com</span>     (2023).     <span class="small-caps" style="font-variant: small-caps;">url</span>:     
<a class="url" href="https://www.swatips.com/articles/20230410.html" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.swatips.com/articles/20230410.html</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-20240902:hood2" style="float: left; clear: left; margin-right: 1em;">
[3]  
</dt><dd class="thebibliography" id="bib-3" style="margin-left: 2.5em;">
<!-- l. 50 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20240902:hood2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon    Hood.    “Sticking    with    a    RAII    Standard”.    In:    <span class="uline" style="text-decoration: underline;">SwATips.com</span>    (2021).    <span class="small-caps" style="font-variant: small-caps;">url</span>:    
<a class="url" href="https://www.swatips.com/articles/20210412.html" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.swatips.com/articles/20210412.html</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-swatips" style="float: left; clear: left; margin-right: 1em;">
[4]  
</dt><dd class="thebibliography" id="bib-4" style="margin-left: 2.5em;">
<!-- l. 50 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon Hood, ed. <span class="uline" style="text-decoration: underline;">SwATips</span>. <a class="url" href="https://www.SwATips.com/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.SwATips.com/</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-20240902:whitehouse" style="float: left; clear: left; margin-right: 1em;">
[5]  
</dt><dd class="thebibliography" id="bib-5" style="margin-left: 2.5em;">
<!-- l. 50 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20240902:whitehouse" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>The White House. <span class="uline" style="text-decoration: underline;">Back to the Building Blocks. A Path Toward Secure and Measurable Software</span>. 2024.
<span class="small-caps" style="font-variant: small-caps;">url</span>:                                                                                                                                 
<a class="url" href="https://www.whitehouse.gov/wp-content/uploads/2024/02/Final-ONCD-Technical-Report.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.whitehouse.gov/wp-content/uploads/2024/02/Final-ONCD-Technical-Report.pdf</span></a>.</p></dd></dl>

 

]]></description>
	</item>
	<item>
		<title>The Zero Trust Paradox: Second Guessing the Good Guys</title>
		<link>https://www.SwATips.com/articles/20240610.html</link>
		<pubDate>Mon, 10 Jun 2024 00:00:00 -0500</pubDate>
<description><![CDATA[

<p style="margin-top: 0; margin-bottom: 0;"><a href="/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/swatips.svg" width="120" alt="SwATips" style="border-top: 0; border-left: 0; border-right: 0;"/></a>| <a href="articles/20240610.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">pdf</a> | <a rel="license" href="http://creativecommons.org/licenses/by/4.0/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/by.svg" width="60" height="21" alt="CC-BY" style="border-top: 0; border-left: 0; border-right: 0;"/></a></p>


<div class="maketitle" style="margin-top: 1em; text-align: center; margin-bottom: 2em;">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead" style="line-height: 1.2; text-align: center;"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a id="x1-3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2</a>]<br/>
</h2>
<div class="author" style="text-align: center;"><span class="ec-lmr-12" style="font-size: 120%;">Jon Hood</span></div><br/>
<div class="date" style="text-align: center;"><span class="ec-lmr-12" style="font-size: 120%;">Monday 10</span><sup class="textsuperscript"><span class="ec-lmr-9" style="font-size: 90%;">th</span></sup><span class="ec-lmr-12" style="font-size: 120%;"> June, 2024</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead" id="the-zero-trust-paradox-second-guessing-the-good-guys" style="line-height: 1.2; font-size: 1.5157em;"><span class="titlemark">1   </span> <a id="x1-10001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>The Zero Trust Paradox: Second Guessing the Good Guys</h3>


<!-- l. 45 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;"><span class="ec-lmr-8" style="font-size: 80%;">Updated Monday 10</span><sup class="textsuperscript"><span class="ec-lmr-9" style="font-size: 90%;">th</span></sup><span class="ec-lmr-8" style="font-size: 80%;"> June, 2024</span>
</p>
<!-- l. 1 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   In February, the DoD CIO issued RMF security control guidance intending to be a starting point for programs
“required to implement zero trust within the DoD.’’[<a id="x1-1001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@20240610:cio" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">5</a>, p. 2] These security controls, when properly implemented,
can help monitor for threats, conduct continuous assessments, automate the security posture evaluations of
components, and support defense-in-depth practices within an organization’s system boundary. In
particular, the overlays expound on continuous ATO requirements for ongoing authorizations under
the Application &amp; Workload Pillar. These controls not only form a solid foundation for which ones
should be continuously assessed, but form a baseline set of rules for any application development to
follow.
</p>
<!-- l. 3 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   But what happens when the assessment data itself is bad? Though these are not tied to individual systems, the
following issues have been observed:
</p>
     

<ul class="itemize1">
<li class="itemize">One organization scanned their software with a custom Fortify rulepack that suppressed or omitted
most rules.
</li>
<li class="itemize">Another organization used SonarQube to scan Ada code, a language not supported by the tool.
</li>
<li class="itemize">A command created a process to do a scan with Coverity, then promptly deleted the results without
ever looking at them.
</li>
<li class="itemize">Enterprise software received an Assess Only assessment approval with the assessment, “The software
was not available for review, so no issues are identified.”</li></ul>


<!-- l. 12 -->
<p class="indent" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   This begs the question that is referred to here as the Zero Trust Paradox. If you trust your implementation of
Zero Trust controls, you have failed to implement the key tenet of Zero Trust: its namesake, <i>Zero
Trust</i>.
</p>
<!-- l. 14 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Zero Trust is not a product you can buy off the shelf nor a contract requirement you can give to a contractor to
implement; it is a foundation principle for conducting security assessments at the right level of granularity to foster
a modular, secure set of information technology.[<a id="x1-1002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@20240610:jackson" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">3</a>]
</p>
<!-- l. 16 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   There is no control in the Risk Management Framework for making sure your program leaders are thinking
about their assessments from a Zero Trust perspective, and a Zero Trust overlay poses the danger of treating what
should be a mindset for assessments as if it were a checklist of requirements to implement. This is demonstrated by
the aforementioned examples. Consider each of these examples with a <i>minimum compliance</i> mindset versus a <i>Zero
Trust</i> mindset to demonstrate why it’s important that security control assessments employ a Zero Trust model for
their initial evaluations.
</p>
<!-- l. 18 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   In the first example, a program used Fortify to fulfill some of the requirements of RMF control SA-11(1), one of
the required controls in the CIO overlay. While the program implemented a good tool for conducting the assessment,
there was no check on whether the tool was configured to properly “employ static code analysis…to
identify common flaws.” The program put trust that the right tool was selected for the right job to build
the right assessment data, but no one documented the trust metrics for if the tools were configured
correctly to build such evidence. A compliance mindset checks the box that SA-11(1) is implemented by
statically scanning the software. A Zero Trust mindset asks, “Why should I trust that data?” and
implements steps to make sure that a rigorous, comprehensive evaluation of the controls is correctly
                                                                                         
                                                                                         
implemented.[<a id="x1-1003" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@20240610:nist800207" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">4</a>]
</p>
<!-- l. 20 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   A “minimal compliance” mindset also plagues the remaining examples. If the mindset is to get an ATO with as
little trouble as possible, then bringing transparency into the security findings of a product will slow down or even
deny authorizations to operate. The Zero Trust architecture requires transparency, and employing efforts
to hide data violates the first core capability of CISA’s Zero Trust Maturity Model: <i>Visibility and
Analytics</i>.[<a id="x1-1004" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@20240610:cisa" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1</a>]
</p>
<!-- l. 22 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   As ISSMs and Authorizing Officials continue to mature in Zero Trust training guidelines, the “minimal
compliance” attitudes will continue to be weeded out. Evaluating your security controls from a Zero Trust
perspective now can save your system from a disastrous security control assessment in the future. You won’t regret
it—trust me!
                                                                                         
                                                                                         
</p>
   

<h3 class="sectionHead" id="references" style="line-height: 1.2; font-size: 1.5157em;"><a id="x1-2000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>References</h3>


<!-- l. 50 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">    
</p>


<dl class="thebibliography"><dt class="thebibliography" id="X0-20240610:cisa" style="float: left; clear: left; margin-right: 1em;">
[1]  
</dt><dd class="thebibliography" id="bib-1" style="margin-left: 2.5em;">
<!-- l. 50 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20240610:cisa" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Cybersecurity and Infrastructure Security Agency. <span class="uline" style="text-decoration: underline;">Zero Trust Maturity Model</span>. Tech. rep. Version 2.0.
2023.                                                             <span class="small-caps" style="font-variant: small-caps;">url</span>:                                                             
<a class="url" href="https://www.cisa.gov/sites/default/files/2023-04/zero_trust_maturity_model_v2_508.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.cisa.gov/sites/default/files/2023-04/zero_trust_maturity_model_v2_508.pdf</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-swatips" style="float: left; clear: left; margin-right: 1em;">
[2]  
</dt><dd class="thebibliography" id="bib-2" style="margin-left: 2.5em;">
<!-- l. 50 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon Hood, ed. <span class="uline" style="text-decoration: underline;">SwATips</span>. <a class="url" href="https://www.SwATips.com/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.SwATips.com/</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-20240610:jackson" style="float: left; clear: left; margin-right: 1em;">
[3]  
</dt><dd class="thebibliography" id="bib-3" style="margin-left: 2.5em;">
<!-- l. 50 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20240610:jackson" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Eric     Jackson.     <span class="uline" style="text-decoration: underline;">When     Zero     Trust     Makes     Zero     Sense</span>.     Aquia.     2024.     <span class="small-caps" style="font-variant: small-caps;">url</span>:     
<a class="url" href="https://blog.aquia.us/blog/2024-05-31-zero_trust_zero_sense/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://blog.aquia.us/blog/2024-05-31-zero_trust_zero_sense/</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-20240610:nist800207" style="float: left; clear: left; margin-right: 1em;">
[4]  
</dt><dd class="thebibliography" id="bib-4" style="margin-left: 2.5em;">
<!-- l. 50 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20240610:nist800207" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>National Institute of Standards and Technology. <span class="uline" style="text-decoration: underline;">Zero Trust Architecture</span>. Tech. rep. Special Publication
(SP) 800-207. Washington, D.C.: U.S. Department of Commerce, 2020. <span class="small-caps" style="font-variant: small-caps;">doi</span>: <a href="https://doi.org/10.6028/NIST.SP.800-207" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">10.6028/NIST.SP.800-
207</span></a>. <span class="small-caps" style="font-variant: small-caps;">url</span>: <a class="url" href="https://nvlpubs.nist.gov/nistpubs/SpecialPublications/NIST.SP.800-207.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://nvlpubs.nist.gov/nistpubs/SpecialPublications/NIST.SP.800-207.pdf</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-20240610:cio" style="float: left; clear: left; margin-right: 1em;">
[5]  
</dt><dd class="thebibliography" id="bib-5" style="margin-left: 2.5em;">
<!-- l. 50 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20240610:cio" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Office  of  the  Chief  Information  Officer.  <span class="uline" style="text-decoration: underline;">Department  of  Defense  Zero  Trust  Overlays</span>.  2024.  <span class="small-caps" style="font-variant: small-caps;">url</span>:  
<a class="url" href="https://dodcio.defense.gov/Portals/0/Documents/Library/ZeroTrustOverlays-2024Feb.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://dodcio.defense.gov/Portals/0/Documents/Library/ZeroTrustOverlays-2024Feb.pdf</span></a>.</p></dd></dl>

 

]]></description>
	</item>
	<item>
		<title>Sorry Root, You're Not the Boss of Me!</title>
		<link>https://www.SwATips.com/articles/20240527.html</link>
		<pubDate>Mon, 27 May 2024 00:00:00 -0500</pubDate>
<description><![CDATA[

<p style="margin-top: 0; margin-bottom: 0;"><a href="/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/swatips.svg" width="120" alt="SwATips" style="border-top: 0; border-left: 0; border-right: 0;"/></a>| <a href="articles/20240527.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">pdf</a> | <a rel="license" href="http://creativecommons.org/licenses/by/4.0/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/by.svg" width="60" height="21" alt="CC-BY" style="border-top: 0; border-left: 0; border-right: 0;"/></a></p>


<div class="maketitle" style="margin-top: 1em; text-align: center; margin-bottom: 2em;">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead" style="line-height: 1.2; text-align: center;"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a id="x1-3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2</a>]<br/>
</h2>
<div class="author" style="text-align: center;"><span class="ec-lmr-12" style="font-size: 120%;">Lane Crawford</span></div><br/>
<div class="date" style="text-align: center;"><span class="ec-lmr-12" style="font-size: 120%;">Monday 27</span><sup class="textsuperscript"><span class="ec-lmr-9" style="font-size: 90%;">th</span></sup><span class="ec-lmr-12" style="font-size: 120%;"> May, 2024</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead" id="sorry-root-youre-not-the-boss-of-me" style="line-height: 1.2; font-size: 1.5157em;"><span class="titlemark">1   </span> <a id="x1-10001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Sorry Root, You’re Not the Boss of Me!</h3>


<!-- l. 45 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;"><span class="ec-lmr-8" style="font-size: 80%;">Updated Monday 20</span><sup class="textsuperscript"><span class="ec-lmr-9" style="font-size: 90%;">th</span></sup><span class="ec-lmr-8" style="font-size: 80%;"> May, 2024</span>
</p>
<!-- l. 1 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   In most Unix-like systems like Linux, the root user can do anything it wants. Everyone knows this. If root wants
to edit a file, that file will say whatever root wants it to. If root wants to delete everything inside a
directory, that directory is toast. Sure, maybe there are some weird hardware things a super-smart
hacker might be able to accomplish to hide something in it,[<a id="x1-1001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@20240527:hood" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1</a>, Malicious Hardware] but there’s no
denying that if root can see the files in the directory, then those files don’t stand a chance. With one
quick command, root can delete a directory and everything inside it, no questions asked. Well, about
that…
</p>
<!-- l. 3 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   During one assurance event, I noticed that the process for updating the boot software for the system was to <span class="ec-lmtt-10" style="font-family: monospace,monospace;">rm
-rf </span>the boot directory and then untar a <span class="ec-lmtt-10" style="font-family: monospace,monospace;">.tgz </span>file containing the new boot software into the now-empty directory.
This reminded me of something I came across while completing a capture-the-flag (CTF) challenge several years
earlier: file attributes. File attributes are meta-data that describe (and, importantly, in some cases modify) file and
directory behavior. File attributes are filesystem dependent, and you’ll find different attributes depending on what
version of OS you’re using. Windows has different attributes than Unix, and other Unix-like systems have distinct
attributes among them. You’ll generally find file attributes for encryption, visibility, and compression (among
others). But for our purposes, it’s enough to know that most flavors of Linux include an attribute for
immutability.
</p>
<!-- l. 5 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Going back to the pentesting event in question, I realized that I could add my own file to the boot directory (or
edit an existing file), make it immutable by issuing the bash command <span class="ec-lmtt-10" style="font-family: monospace,monospace;">chattr +i that_file</span>, and prevent
that file from being modified or deleted without first removing the immutability attribute (<span class="ec-lmtt-10" style="font-family: monospace,monospace;">chattr -i
that_file</span>). This meant that when root called <span class="ec-lmtt-10" style="font-family: monospace,monospace;">rm -rf</span>, anything possessing the immutable attribute
would not be deleted. And since both files and directories can be made immutable, this effectively
meant that I could make whatever changes I wanted inside the boot directory and have those changes
persist.
</p>
<!-- l. 7 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   And what about the untarring? Normally the <span class="ec-lmtt-10" style="font-family: monospace,monospace;">tar </span>command would overwrite files with the same name; however,
any files marked immutable would not be overwritten. In that case, <span class="ec-lmtt-10" style="font-family: monospace,monospace;">tar </span>would throw an error for each of those files,
stating there was an error trying to overwrite them. But since everyone knows using root to <span class="ec-lmtt-10" style="font-family: monospace,monospace;">rm -rf </span>removes
everything, the output from tar was not being checked to ensure it completed successfully. The result was
that I could make whatever changes I wanted inside the boot directory, have those changes persist
through the update process, and the update process would return a message that the update happened
successfully.
</p>
<!-- l. 9 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Hopefully this will help you realize the importance of understanding little-known Linux attributes and not
assuming that simple functions that appear to be straightforward are actually completing the way
you want them to. Functions have return values for a reason; check them before assuming everything
worked!
                                                                                         
                                                                                         
</p>
   

<h3 class="sectionHead" id="references" style="line-height: 1.2; font-size: 1.5157em;"><a id="x1-2000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>References</h3>


<!-- l. 50 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">    
</p>


<dl class="thebibliography"><dt class="thebibliography" id="X0-20240527:hood" style="float: left; clear: left; margin-right: 1em;">
[1]  
</dt><dd class="thebibliography" id="bib-1" style="margin-left: 2.5em;">
<!-- l. 50 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20240527:hood" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon       Hood.       “Side-Channel       Attacks”.       In:       <span class="uline" style="text-decoration: underline;">SwATips.com</span>       (2021).       <span class="small-caps" style="font-variant: small-caps;">url</span>:       
<a class="url" href="https://www.swatips.com/articles/20210524.html" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.swatips.com/articles/20210524.html</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-swatips" style="float: left; clear: left; margin-right: 1em;">
[2]  
</dt><dd class="thebibliography" id="bib-2" style="margin-left: 2.5em;">
<!-- l. 50 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon Hood, ed. <span class="uline" style="text-decoration: underline;">SwATips</span>. <a class="url" href="https://www.SwATips.com/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.SwATips.com/</span></a>.</p></dd></dl>

 

]]></description>
	</item>
	<item>
		<title>Assess Only v. Assess and Authorize</title>
		<link>https://www.SwATips.com/articles/20240212.html</link>
		<pubDate>Mon, 12 Feb 2024 00:00:00 -0600</pubDate>
<description><![CDATA[

<p style="margin-top: 0; margin-bottom: 0;"><a href="/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/swatips.svg" width="120" alt="SwATips" style="border-top: 0; border-left: 0; border-right: 0;"/></a>| <a href="articles/20240212.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">pdf</a> | <a rel="license" href="http://creativecommons.org/licenses/by/4.0/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/by.svg" width="60" height="21" alt="CC-BY" style="border-top: 0; border-left: 0; border-right: 0;"/></a></p>


<div class="maketitle" style="margin-top: 1em; text-align: center; margin-bottom: 2em;">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead" style="line-height: 1.2; text-align: center;"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a id="x1-3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">4</a>]<br/>
</h2>
<div class="author" style="text-align: center;"><span class="ec-lmr-12" style="font-size: 120%;">Jon Hood and Kevin Keen</span></div><br/>
<div class="date" style="text-align: center;"><span class="ec-lmr-12" style="font-size: 120%;">Monday 12</span><sup class="textsuperscript"><span class="ec-lmr-9" style="font-size: 90%;">th</span></sup><span class="ec-lmr-12" style="font-size: 120%;"> February, 2024</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead" id="assess-only-v-assess-and-authorize" style="line-height: 1.2; font-size: 1.5157em;"><span class="titlemark">1   </span> <a id="x1-10001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Assess Only v. Assess and Authorize</h3>


<!-- l. 45 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;"><span class="ec-lmr-8" style="font-size: 80%;">Updated Friday 22</span><sup class="textsuperscript"><span class="ec-lmr-9" style="font-size: 90%;">nd</span></sup><span class="ec-lmr-8" style="font-size: 80%;"> March, 2024</span>
</p>
<!-- l. 1 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   A trend we have been seeing lately in the DoD is the misuse of the Assess Only framework. The Assess Only
process was created to provide a way of assessing unique technologies below the system level which do not require an
authorization like an Authority to Operate, Authority to Connect, Authority to Test, or their interim kin (ATO,
ATC, ATT, IATO, IATC, IATT).[<a id="x1-1001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@20240212:dodi851001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">3</a>, p. 13]
</p>
<!-- l. 3 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Misusing the Assess Only process results in a security hole. The primary result of misuse includes bypassing the
Assess &amp; Authorize (A&amp;A) process protections. This evasion of the A&amp;A process results in increased
operational risk, inadequate risk management, a lack of accountability, and a misalignment with mission
requirements. To help organizations identify their holes in Assess Only processes, the following items provide
a litmus test for making sure that your organization does not abuse RMF policies in a dangerous
way:
</p>
<!-- l. 5 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead" id="assess-only-systems" style="line-height: 1.2; font-size: 1.3195em;"><span class="titlemark">1.1   </span> <a id="x1-20001.1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Assess Only Systems</h4>


<!-- l. 6 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Referring to “Assess Only Systems” indicates a lack of understanding of what may go through the Assess
Only process. Systems (including Major Applications, PIT Systems, and SIS/CRNs) must go through
the Assess &amp; Authorize process. Organizations that refer to “Assess Only Systems” demonstrate a
misunderstanding of what an assessment approval is intended to accomplish. Words have meaning,
and using the wrong words creates an inconsistency which introduces weaknesses in a cybersecurity
program.
</p>
<!-- l. 8 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   The guidance in DoDI 8500.01 (Figure <a href="#-assess-only-and-assess-authorize-in-dod-policy" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1<!-- tex4ht:ref: fig:20240212:dodit  --></a>) can help in understanding this distinction.[<a id="x1-2001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@20240212:dodi850001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2</a>] Systems do not qualify
for the Assess Only process.
</p>
   

<figure class="figure" id="-assess-only-and-assess-authorize-in-dod-policy" style="text-align: center;"> 

                                                                                         
                                                                                         
<a id="x1-20021" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>
                                                                                         
                                                                                         
<!-- l. 12 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><img alt="PIC" height="146" src="https://www.swatips.com/articles/images/20240212-1.png" width="398"/>
</p>
<figcaption class="caption" style="margin-top: 1em; text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Figure 1: </span><span class="content">Assess Only and Assess &amp; Authorize in DoD Policy</span></figcaption><!-- tex4ht:label?: x1-20021  -->
                                                                                         
                                                                                         
   
</figure>


<h4 class="subsectionHead" id="what-is-being-approved" style="line-height: 1.2; font-size: 1.3195em;"><span class="titlemark">1.2   </span> <a id="x1-30001.2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>What is Being Approved</h4>


<!-- l. 18 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">There are two flavors of the Assess Only process. A program may use the <i>Assess &amp; Approve</i> process to approve
single-purpose, non-connecting IT-enabled devices and services, or they can use the <i>Assess &amp; Incorporate</i> process to
approve an assessment which can be associated with or incorporated into an already authorized boundary.[<a id="x1-3001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@20240212:vaglia2017" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">7</a>, p. 11]
For software applications, notice that the assessment is the focal point of the approval, and the system that
wants to associate with that assessment should have a process for incorporating it into their boundary.
This article does not delve into the assessments of single-purpose PIT components are Assessed and
Approved, such as single-purpose It-enabled devices that “do not become a part of an incorporating
system’s authorization boundary.”[<a id="x1-3002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@20240212:legislation" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">5</a>, DoD CIO Risk Management Framework Assess Only Guidance
2017]
</p>
<!-- l. 20 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Reciprocity requires the incorporating organization to perform due diligence when associating with an approved
assessment, and that includes review of the assessment data. Organizations that treat an Assessment Approval of
software as if it were a blanket, protean approval of the product (rather than an approval of the assessment) are
bypassing the authorization mechanism in RMF and the reciprocity controls of their organization if the process does
not include reviewing the assessment data.
</p>
<!-- l. 22 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead" id="assess-only-ato-atc-and-att" style="line-height: 1.2; font-size: 1.3195em;"><span class="titlemark">1.3   </span> <a id="x1-40001.3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Assess Only ATO, ATC, and ATT</h4>


<!-- l. 23 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">An ATO, ATC, and ATT (and by extension, their interim cousins, IATO, IATC, and IATT) begin with the word
<i>Authority</i>. An <i>Authorization</i> requires the Assess <i>&amp; Authorize</i> process. By definition, an Assess Only is not used in
the place of an operational authorization.
</p>
<!-- l. 25 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   An authorized boundary which does have an ATO, ATC, or ATT may define policies for associating with an
approved assessment to become an authority for the operation of IT below the system level. Those policies should
include the review of Assess Only data; however, systems and networks, like the DODIN, may require a full ATO or
ATC under the A&amp;A process.[<a id="x1-4001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@20240212:disncpg" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1</a>]
</p>
<!-- l. 27 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Organizations which refer to an “Assess Only ATO” or “Assess Only ATC” are trying to mix Step 6 of the RMF
process (Authorization) with an approval mechanism that ends at Step 5 (Assessment).
</p>
<!-- l. 29 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead" id="assess-only-conmon" style="line-height: 1.2; font-size: 1.3195em;"><span class="titlemark">1.4   </span> <a id="x1-50001.4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Assess Only ConMon</h4>


<!-- l. 30 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Taking the misuse of the Assess Only construct a step further are organizations which refer to an “Assess Only
ConMon.” These organizations attempt to implement Step 7 of the RMF process (Monitoring) in non-standard
ways. <i>Monitoring</i> in the RMF process refers to the surveillance of authorized assets and controls approved in the
Step 6 (Authorized) boundary.[<a id="x1-5001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@20240212:nist80037rev2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">6</a>] This is one of the reasons why DoD elements often refer to this as a ConMon
Authorization or Continuous ATO (cATO). Consider the wheel in Figure <a href="#-rmf-process-wheel" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2<!-- tex4ht:ref: fig:20240212:rmfwheel  --></a> to help understand where authorization
and monitoring fall in the RMF process.
</p>
   

<figure class="figure" id="-rmf-process-wheel" style="text-align: center;"> 

                                                                                         
                                                                                         
<a id="x1-50022" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>
                                                                                         
                                                                                         
<!-- l. 34 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><img alt="PIC" height="276" src="https://www.swatips.com/articles/images/20240212-2.png" width="284"/>
</p>
<figcaption class="caption" style="margin-top: 1em; text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Figure 2: </span><span class="content">RMF Process Wheel</span></figcaption><!-- tex4ht:label?: x1-50022  -->
                                                                                         
                                                                                         
   
</figure>


<!-- l. 39 -->
<p class="indent" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   Continuous monitoring (ConMon) is a requirement for a robust continuous authorization process. It is an
<i>operational</i> construct which is why it requires an Authority to <i>Operate</i> (ATO). Organizations can implement
continuous assessment for products below the system level, but to redefine continuous monitoring as meaning
continuous assessment gives organizations a false sense of security by bypassing Authorization and answering the
final RMF step at the wrong level.
</p>
   

<h4 class="subsectionHead" id="conclusion" style="line-height: 1.2; font-size: 1.3195em;"><span class="titlemark">1.5   </span> <a id="x1-60001.5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Conclusion</h4>


<!-- l. 42 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Organizations trying to implement the RMF process should be commended. A program doing their due diligence to
implement cybersecurity principles should consider the litmus test provided here to determine if their processes
comply with existing DoD guidance.
                                                                                         
                                                                                         
</p>
   

<h3 class="sectionHead" id="references" style="line-height: 1.2; font-size: 1.5157em;"><a id="x1-7000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>References</h3>


<!-- l. 50 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">    
</p>


<dl class="thebibliography"><dt class="thebibliography" id="X0-20240212:disncpg" style="float: left; clear: left; margin-right: 1em;">
[1]  
</dt><dd class="thebibliography" id="bib-1" style="margin-left: 2.5em;">
<!-- l. 50 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20240212:disncpg" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Defense             Information             Systems             Agency.             <span class="uline" style="text-decoration: underline;">Defense             Informatoin
System Network (DISN) Connection Process Guide (CPG)</span>. Tech. rep. Fort Meade, Maryland, 2023.
<span class="small-caps" style="font-variant: small-caps;">url</span>: <a class="url" href="https://dl.dod.cyber.mil/wp-content/uploads/connect/pdf/unclass-DISN_CPG.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://dl.dod.cyber.mil/wp-content/uploads/connect/pdf/unclass-DISN_CPG.pdf</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-20240212:dodi850001" style="float: left; clear: left; margin-right: 1em;">
[2]  
</dt><dd class="thebibliography" id="bib-2" style="margin-left: 2.5em;">
<!-- l. 50 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20240212:dodi850001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Department  of  Defense.  <span class="uline" style="text-decoration: underline;">Department  of  Defense  Instruction  8500.01</span>.  Tech.  rep.  Incorporating
Change   1,   October   7,   2019.   Washington,   D.C.:   Department   of   Defense,   2019.   <span class="small-caps" style="font-variant: small-caps;">url</span>:   
<a class="url" href="https://www.esd.whs.mil/portals/54/documents/dd/issuances/dodi/850001_2014.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.esd.whs.mil/portals/54/documents/dd/issuances/dodi/850001_2014.pdf</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-20240212:dodi851001" style="float: left; clear: left; margin-right: 1em;">
[3]  
</dt><dd class="thebibliography" id="bib-3" style="margin-left: 2.5em;">
<!-- l. 50 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20240212:dodi851001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Department  of  Defense.  <span class="uline" style="text-decoration: underline;">Department  of  Defense  Instruction  8510.01.  Risk  Management  Framework
for   DoD   Systems</span>.   Tech.   rep.   Washington,   D.C.:   Department   of   Defense,   2022.   <span class="small-caps" style="font-variant: small-caps;">url</span>:   
<a class="url" href="https://www.esd.whs.mil/Portals/54/Documents/DD/issuances/dodi/851001p.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.esd.whs.mil/Portals/54/Documents/DD/issuances/dodi/851001p.pdf</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-swatips" style="float: left; clear: left; margin-right: 1em;">
[4]  
</dt><dd class="thebibliography" id="bib-4" style="margin-left: 2.5em;">
<!-- l. 50 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon Hood, ed. <span class="uline" style="text-decoration: underline;">SwATips</span>. <a class="url" href="https://www.SwATips.com/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.SwATips.com/</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-20240212:legislation" style="float: left; clear: left; margin-right: 1em;">
[5]  
</dt><dd class="thebibliography" id="bib-5" style="margin-left: 2.5em;">
<!-- l. 50 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20240212:legislation" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>SERDP-ESTCP.  <span class="uline" style="text-decoration: underline;">Legislation,  Instructions,  Manuals,  Policies,  Plans  and  Memos</span>.  Tech.  rep.  <span class="small-caps" style="font-variant: small-caps;">url</span>:  
<a class="url" href="https://serdp-estcp.mil/page/f7ad7b6f-e8ef-11ec-9685-026db1cbe810" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://serdp-estcp.mil/page/f7ad7b6f-e8ef-11ec-9685-026db1cbe810</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-20240212:nist80037rev2" style="float: left; clear: left; margin-right: 1em;">
[6]  
</dt><dd class="thebibliography" id="bib-6" style="margin-left: 2.5em;">
<!-- l. 50 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20240212:nist80037rev2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>National  Institute  of  Standards  and  Technology.  <span class="uline" style="text-decoration: underline;">Risk  Management  Framework  for  Information
Systems  and  Organizations</span>.  Tech.  rep.  Special  Publication  (SP)  800-37  Revision  2.  Washington,
D.C.:  U.S.  Department  of  Commerce,  2018.  <span class="small-caps" style="font-variant: small-caps;">doi</span>:  <a href="https://doi.org/10.6028/NIST.SP.800-37r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">10 . 6028 / NIST . SP . 800 - 37r2</span></a>.  <span class="small-caps" style="font-variant: small-caps;">url</span>:  
<a class="url" href="https://nvlpubs.nist.gov/nistpubs/SpecialPublications/NIST.SP.800-37r2.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://nvlpubs.nist.gov/nistpubs/SpecialPublications/NIST.SP.800-37r2.pdf</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-20240212:vaglia2017" style="float: left; clear: left; margin-right: 1em;">
[7]  
</dt><dd class="thebibliography" id="bib-7" style="margin-left: 2.5em;">
<!-- l. 50 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20240212:vaglia2017" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Laura Vaglia and Jey Castleberry. <span class="uline" style="text-decoration: underline;">Facility Related Control System Inventory</span>. Tech. rep. 2017. <span class="small-caps" style="font-variant: small-caps;">url</span>: 
<a class="url" href="https://usarsustainabilitydotcom.files.wordpress.com/2017/12/facility-related-control-system-inventory.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://usarsustainabilitydotcom.files.wordpress.com/2017/12/facility-related-control-system-inventory.pdf</span></a>.</p></dd></dl>

 

]]></description>
	</item>
	<item>
		<title>A History of Verification, Validation, and Code Scanning</title>
		<link>https://www.SwATips.com/articles/20230918.html</link>
		<pubDate>Mon, 18 Sep 2023 00:00:00 -0500</pubDate>
<description><![CDATA[

<p style="margin-top: 0; margin-bottom: 0;"><a href="/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/swatips.svg" width="120" alt="SwATips" style="border-top: 0; border-left: 0; border-right: 0;"/></a>| <a href="articles/20230918.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">pdf</a> | <a rel="license" href="http://creativecommons.org/licenses/by/4.0/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/by.svg" width="60" height="21" alt="CC-BY" style="border-top: 0; border-left: 0; border-right: 0;"/></a></p>


<div class="maketitle" style="margin-top: 1em; text-align: center; margin-bottom: 2em;">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead" style="text-align: center;"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a id="x1-3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">5</a>]<br/>
</h2>
<div class="author" style="text-align: center;"><span class="ec-lmr-12" style="font-size: 120%;">Jon Hood</span></div><br/>
<div class="date" style="text-align: center;"><span class="ec-lmr-12" style="font-size: 120%;">Monday 18</span><sup class="textsuperscript"><span class="ec-lmr-9" style="font-size: 90%;">th</span></sup><span class="ec-lmr-12" style="font-size: 120%;"> September, 2023</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead" id="a-history-of-verification-validation-and-code-scanning"><span class="titlemark">1   </span> <a id="x1-10001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>A History of Verification, Validation, and Code Scanning</h3>


<!-- l. 44 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;"><span class="ec-lmr-8" style="font-size: 80%;">Updated Monday 18</span><sup class="textsuperscript"><span class="ec-lmr-9" style="font-size: 90%;">th</span></sup><span class="ec-lmr-8" style="font-size: 80%;"> September, 2023</span>
</p>
<!-- l. 1 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   One of the DoD and NASA trends we have seen lately is the confusion of functional VV&amp;A with
cybersecurity tasks. The blurring of these two distinct efforts from organizations implementing an
IV&amp;V program and a cybersecurity program can cause collisions with the definitions of what is being
accomplished.
</p>
<!-- l. 3 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Static code analysis is one of those definitions. The meaning of static code analysis is very different from a
Functional, VV&amp;A IV&amp;V program when compared to the static code analysis conducted by a cybersecurity
program. The etymology of static analysis comes from completely diverging goals.
</p>
<!-- l. 5 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead" id="verification-and-validation"><span class="titlemark">1.1   </span> <a id="x1-20001.1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Verification and Validation</h4>


<!-- l. 6 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">“Haste makes waste.” In the 1960s and 1970s, a static code walkthrough was recommended before ever compiling the
module. “The verification sessions should occur before the first compilation of the module.” Since “few if any
compilers are capable of detecting every syntax error,” syntax errors were considered logic errors in
the software.[<a id="x1-2001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@20230918:myers1976" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">8</a>, pp. 144, 149, 292] The static analysis and formal walkthrough of code from a V&amp;V
perspective has the goal of verifying the integrity of the logic that goes into the design of the software
module.
</p>
<!-- l. 8 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   This ties into the current DoD VV&amp;A process for Verification, Validation, and Accreditation in DoD Instruction
5000.61. These are defined as:[<a id="x1-2002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@20230918:dodi500061" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2</a>] </p>


<ul class="itemize1">     
<li class="itemize"><i>Verification</i>—The process of determining that a model or simulation implementation and its associated
data accurately represent the developer’s conceptual description and specifications.
</li>
<li class="itemize"><i>Validation</i>—The process of determining the degree to which a model or simulation and its associated
data are an accurate representation of the real world from the perspective of the intended uses of the
model.
</li>
<li class="itemize"><i>Accreditation</i>—The  official  certification  that  a  model  or  simulation  and  its  associated  data  are
acceptable for use for a specific purpose.</li></ul>


<!-- l. 15 -->
<p class="indent" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   One way to accomplish these goals is by implementing IEEE 1012, the IEEE Standard for System, Software, and
Hardware Verification and Validation. This lays out the purpose of V&amp;V: “to help the organization build quality
into the system during the life cycle. V&amp;V processes provide an objective assessment of products and processes
throughout the life cycle. This assessment demonstrates whether requirements are correct, complete, accurate,
consistent, and testable.” This standard recommends a process for inspecting source code to “verify that
the source code implementation is traceable to the design” and a static walkthrough of the code for
the same types of logic issues Myers mentions in his book.[<a id="x1-2003" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@20230918:ieee1012" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">6</a>, pp. 10, 213, 216] Cybersecurity static
code analysis scans are circumstantial evidence used to demonstrate the testability of the codebase.[<a href="#cite.0@20230918:ieee1012" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">6</a>,
p. 206]
</p>
<!-- l. 17 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   If you want to certify that a simulation or software model correctly reflects the real-world scenario and
requirements that define the software module, VV&amp;A is the way to go. Static code walkthroughs are often employed
as a tool to accomplish this task.
</p>
<!-- l. 19 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Static analysis tools for proving the logic of code include flow provability tools such as GNATprove, property
checkers[<a id="x1-2004" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@20230918:foster2015trends" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">4</a>] such as RapidCheck and QuickCheck[<a id="x1-2005" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@20230918:jones2003" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">7</a>], SlithIR SSA, Prusti, and many more static analysis
tools.
                                                                                         
                                                                                         
</p>
<!-- l. 21 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead" id="cybersecurity"><span class="titlemark">1.2   </span> <a id="x1-30001.2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Cybersecurity</h4>


<!-- l. 23 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Static analysis is defined in the cybersecurity realm by DoDI 8500.01 as part of the Risk Management
Framework which implements NIST 800-53.[<a id="x1-3001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@20230918:dodi850001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">3</a>] Static analysis and the tools which conduct it are defined in
controls RA-5, SA-11, and SA-11(1). “Static code analysis provides a technology and methodology for
security reviews and includes checking for weaknesses in the code as well as for the incorporation of
libraries or other included code with known vulnerabilities or that are out-of-date and not supported.
Static code analysis can be used to identify vulnerabilities and enforce secure coding practices.”[<a id="x1-3002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@20230918:nist80053rev5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">10</a>,
p. 277]
</p>
<!-- l. 25 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Cybersecurity static analysis usually maps issues against Common Weakness Enumerations (CWEs), Common
Vulnerabilities and Exposures (CVEs), and software assurance defects. A good framework for defining these secure
code security analysis tools is NIST 500-268 which defines functional requirements of cybersecurity static analysis
tools. Buffer overflows (such as stack and heap overflows, CWEs 121 and 122), uninitialized variables (CWE-457),
TOCTOU (CWE-367), and injections (such as command, SQL, and LDAP injections, CWEs 78, 89, and 90) are
examples of cybersecurity concerns.[<a id="x1-3003" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@20230918:nist500268" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">9</a>]
</p>
<!-- l. 27 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Tools that conduct these checks include Fortify, Checkmarx, and many more. The performance of these scans is
implemented as part of the Application Security and Development STIG[<a id="x1-3004" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@20230918:ASDStig" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1</a>] which provides even more guidance on
how to establish coding standards (SV-222653r879887_rule), independent testing (SV-222627r879887_rule), and
even specifies some minimum requirements for static code analysis such as race conditions (SV-222567r879887_rule),
storing sensitive information in hidden fields (SV-222601r879812_rule), cross-site scripting (XSS)
(SV-222602r879652_rule), cross-site request forgeries (CSRF) (SV-222603r879652_rule), command injections
(SV-222604r879652_rule), canonical representation vulnerabilities (SV-222605r879652_rule), input
validation/handling (SV-222606r879652_rule/SV-222609r879818_rule), SQL injections (SV-222607r879652_rule),
XML-based attacks (SV-222608r879652_rule), and overflows (including buffer overflow, heap overflows, stack
overflows, and wrap-around issues) (SV-222612r879821_rule).
</p>
<!-- l. 29 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead" id="conclusion"><span class="titlemark">1.3   </span> <a id="x1-40001.3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Conclusion</h4>


<!-- l. 31 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">We have seen an increase in VV&amp;A organizations claiming that they’re conducting the static analysis defined by
VV&amp;A processes yet instead conduct cybersecurity static analyses. A good program will incorporate the DoDI
5000.61 requirements, and static analysis tools that speak the language of logic, proofs, and contracts is one small
portion of the capabilities such organizations should implement. If your program needs accreditation or
authorization from a cybersecurity perspective (such as an Assess and Authorize under RMF), a cybersecurity
program will employ static analysis tools that speak the language of weaknesses, vulnerabilities, and coding
standards.
</p>
<!-- l. 33 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Perform a litmus test on your own programs today. Is your VV&amp;A program using cybersecurity tools such as
Cppcheck, Code Dx, Checkmarx, Fortify, or Coverity? Suppose your program has a requirement to draw a circle.
These are the tools that allow you to say, “Yeah, verily, this is the most secure square that has ever been drawn on a
screen.” But these tools do not allow you to say, “You drew a square when the requirements contract for the code is
that you draw a circle.” That involves provability and qualification testing that your VV&amp;A program should be
concentrating on.
                                                                                         
                                                                                         
</p>
   

<h3 class="sectionHead" id="references"><a id="x1-50001.3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>References</h3>


<!-- l. 49 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">     
</p>


<dl class="thebibliography"><dt class="thebibliography" id="X0-20230918:ASDStig" style="float: left; clear: left; margin-right: 1em;"> 
[1]  
</dt><dd class="thebibliography" id="bib-1" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20230918:ASDStig" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Application Security and Development STIG V5R3.       Tech.       rep.       July       2023.       <span class="small-caps" style="font-variant: small-caps;">url</span>:
<a class="url" href="https://dl.dod.cyber.mil/wp-content/uploads/stigs/zip/U_ASD_V5R3_STIG.zip" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://dl.dod.cyber.mil/wp-content/uploads/stigs/zip/U_ASD_V5R3_STIG.zip</span></a>.
</p>     
</dd>
<dt class="thebibliography" id="X0-20230918:dodi500061" style="float: left; clear: left; margin-right: 1em;">
[2]  
</dt><dd class="thebibliography" id="bib-2" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20230918:dodi500061" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Department   of   Defense.   Department of Defense Instruction 5000.61.   Tech.   rep.   Incorporating
Change   1,   October   15,   2018.   Washington,   D.C.:   Department   of   Defense,   2018.   <span class="small-caps" style="font-variant: small-caps;">url</span>:
<a class="url" href="https://www.esd.whs.mil/Portals/54/Documents/DD/issuances/dodi/500061p.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.esd.whs.mil/Portals/54/Documents/DD/issuances/dodi/500061p.pdf</span></a>.
</p>     
</dd>
<dt class="thebibliography" id="X0-20230918:dodi850001" style="float: left; clear: left; margin-right: 1em;">
[3]  
</dt><dd class="thebibliography" id="bib-3" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20230918:dodi850001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Department of Defense. Department of Defense Instruction 8500.01. Tech. rep. Incorporating Change
1,     October     7,     2019.     Washington,     D.C.:     Department     of     Defense,     2019.     <span class="small-caps" style="font-variant: small-caps;">url</span>:
<a class="url" href="https://www.esd.whs.mil/portals/54/documents/dd/issuances/dodi/850001_2014.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.esd.whs.mil/portals/54/documents/dd/issuances/dodi/850001_2014.pdf</span></a>.
</p>     
</dd>
<dt class="thebibliography" id="X0-20230918:foster2015trends" style="float: left; clear: left; margin-right: 1em;">
[4]  
</dt><dd class="thebibliography" id="bib-4" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20230918:foster2015trends" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Harry    D    Foster.    “Trends    in    functional    verification:    A    2014    industry    study”.    In:
Proceedings of the 52nd Annual Design Automation Conference
. 2015, pp. 1–6.
</p>     
</dd>
<dt class="thebibliography" id="X0-swatips" style="float: left; clear: left; margin-right: 1em;">
[5]  
</dt><dd class="thebibliography" id="bib-5" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon Hood, ed. SwATips.     <a class="url" href="https://www.SwATips.com/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.SwATips.com/</span></a>.
</p>     
</dd>
<dt class="thebibliography" id="X0-20230918:ieee1012" style="float: left; clear: left; margin-right: 1em;">
[6]  
</dt><dd class="thebibliography" id="bib-6" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20230918:ieee1012" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>IEEE Standards Association. “IEEE Standard for System, Software, and Hardware Verification and
Validation”. In: IEEE Std 1012-2016 (Revision of IEEE Std 1012-2012/ Incorporates IEEE Std 1012-2016/Cor1-2017)
(2017), pp. 1–260. <span class="small-caps" style="font-variant: small-caps;">doi</span>: <a href="https://doi.org/10.1109/IEEESTD.2017.8055462" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">10.1109/IEEESTD.2017.8055462</span></a>.
</p>     
</dd>
<dt class="thebibliography" id="X0-20230918:jones2003" style="float: left; clear: left; margin-right: 1em;">
[7]  
</dt><dd class="thebibliography" id="bib-7" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20230918:jones2003" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Andrew  Jones  and  Jeremy  Sonander.  “An  Introduction  To  Property  Checkers  For  Functional
Verification”. In: (2003). <span class="small-caps" style="font-variant: small-caps;">url</span>:     <a class="url" href="https://averant.com:8443/assets/pdf/Intro_PropVer.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://averant.com:8443/assets/pdf/Intro_PropVer.pdf</span></a>.
</p>     
</dd>
<dt class="thebibliography" id="X0-20230918:myers1976" style="float: left; clear: left; margin-right: 1em;">
[8]  
</dt><dd class="thebibliography" id="bib-8" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20230918:myers1976" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Glenford J Myers. Software Reliability. John Wiley &amp; Sons, Inc., 1976. <span class="small-caps" style="font-variant: small-caps;">isbn</span>: 978-0-471-62765-4.
</p>     
</dd>
<dt class="thebibliography" id="X0-20230918:nist500268" style="float: left; clear: left; margin-right: 1em;">
[9]  
</dt><dd class="thebibliography" id="bib-9" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20230918:nist500268" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>National                                Institute                                of                                Standards
and Technology. Security and Privacy Controls for Information Systems and Organizations. Tech. rep.
Special Publication (SP) 500-268 v1.1. Washington, D.C.: U.S. Department of Commerce, 2011. <span class="small-caps" style="font-variant: small-caps;">doi</span>: <a href="https://doi.org/10.6028/NIST.SP.500-268v1.1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">10    .    6028    /    NIST    .    SP    .    500    -    268v1    .    1</span></a>.       <span class="small-caps" style="font-variant: small-caps;">url</span>:
<a class="url" href="https://nvlpubs.nist.gov/nistpubs/Legacy/SP/nistspecialpublication500-268v1.1.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://nvlpubs.nist.gov/nistpubs/Legacy/SP/nistspecialpublication500-268v1.1.pdf</span></a>.
</p>     
</dd>
<dt class="thebibliography" id="X0-20230918:nist80053rev5" style="float: left; clear: left; margin-right: 1em;">
[10]  
</dt><dd class="thebibliography" id="bib-10" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20230918:nist80053rev5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>National                                Institute                                of                                Standards
and Technology. Security and Privacy Controls for Information Systems and Organizations. Tech. rep.
Special                Publication                (SP)                800-53                Revision                5.
Washington, D.C.: U.S. Department of Commerce, 2020. <span class="small-caps" style="font-variant: small-caps;">doi</span>: <a href="https://doi.org/10.6028/NIST.SP.800-53r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">10.6028/NIST.SP.800-53r5</span></a>. <span class="small-caps" style="font-variant: small-caps;">url</span>:
<a class="url" href="https://nvlpubs.nist.gov/nistpubs/SpecialPublications/NIST.SP.800-53r5.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://nvlpubs.nist.gov/nistpubs/SpecialPublications/NIST.SP.800-53r5.pdf</span></a>.</p></dd></dl>

                                                                                         
                                                                                         
   
 

]]></description>
	</item>
	<item>
		<title>Checkmarx: Use of Obsolete Function</title>
		<link>https://www.SwATips.com/articles/20230515.html</link>
		<pubDate>Mon, 15 May 2023 00:00:00 -0500</pubDate>
<description><![CDATA[

<p style="margin-top: 0; margin-bottom: 0;"><a href="/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/swatips.svg" width="120" alt="SwATips" style="border-top: 0; border-left: 0; border-right: 0;"/></a>| <a href="articles/20230515.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">pdf</a> | <a rel="license" href="http://creativecommons.org/licenses/by/4.0/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/by.svg" width="60" height="21" alt="CC-BY" style="border-top: 0; border-left: 0; border-right: 0;"/></a></p>


<div class="maketitle" style="margin-top: 1em; text-align: center; margin-bottom: 2em;">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead" style="line-height: 1.2; text-align: center;"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a id="x1-3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1</a>]<br/>
</h2>
<div class="author" style="text-align: center;"><span class="ec-lmr-12" style="font-size: 120%;">Kevin Keen</span></div><br/>
<div class="date" style="text-align: center;"><span class="ec-lmr-12" style="font-size: 120%;">Monday 15</span><sup class="textsuperscript"><span class="ec-lmr-9" style="font-size: 90%;">th</span></sup><span class="ec-lmr-12" style="font-size: 120%;"> May, 2023</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead" style="line-height: 1.2; font-size: 1.5157em;"><span class="titlemark">1   </span> <a id="x1-10001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Checkmarx: Use of Obsolete Function</h3>


<!-- l. 44 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;"><span class="ec-lmr-8" style="font-size: 80%;">Updated Saturday 13</span><sup class="textsuperscript"><span class="ec-lmr-9" style="font-size: 90%;">th</span></sup><span class="ec-lmr-8" style="font-size: 80%;"> May, 2023</span>
</p>
<!-- l. 1 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   One of the things that Checkmarx can scan for is <i>Use of Obsolete Functions</i>. While scanning some Java code
recently, we were pleasantly surprised to find that the scanner is smart enough to look at the definition of a method
and, if the implementation is marked with the <span class="ec-lmtt-10" style="font-family: monospace,monospace;">@Deprecated </span>annotation, it will mark the call site as a finding. This
is desired behavior, and we applaud the scanner for considering that annotation. That having been said, there are
several frequent false positives for which to watch. We speculate that much of the scanning for this particular finding
is based on a purely text search.
</p>
<!-- l. 3 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Some of the false positives we saw were flagging <span class="ec-lmtt-10" style="font-family: monospace,monospace;">hashCode </span>as an obsolete function. This made no sense to us, as
<span class="ec-lmtt-10" style="font-family: monospace,monospace;">hashCode </span>is an integral part of the language and has never been deprecated to our knowledge. Upon further
inspection, it became apparent that the only uses of <span class="ec-lmtt-10" style="font-family: monospace,monospace;">hashCode </span>which were being flagged were on instances where the
variable was named <span class="ec-lmtt-10" style="font-family: monospace,monospace;">identity</span>. There was an <span class="ec-lmtt-10" style="font-family: monospace,monospace;">Identity </span>class (<span class="ec-lmtt-10" style="font-family: monospace,monospace;">java.security.Identity</span>) which has long
since been deprecated. As the whole class was deprecated, that included the <span class="ec-lmtt-10" style="font-family: monospace,monospace;">hashCode </span>method of
that class. We presume a text search is being performed that will flag any <span class="ec-lmtt-10" style="font-family: monospace,monospace;">identity.hashCode </span>as
deprecated regardless of whether or not the variable <span class="ec-lmtt-10" style="font-family: monospace,monospace;">identity </span>is actually a <span class="ec-lmtt-10" style="font-family: monospace,monospace;">java.security.Identity</span>
object.
</p>
<!-- l. 5 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Another group of false positives stem from the use of <span class="ec-lmtt-10" style="font-family: monospace,monospace;">component </span>and <span class="ec-lmtt-10" style="font-family: monospace,monospace;">size</span>. These findings flag the use of
the <span class="ec-lmtt-10" style="font-family: monospace,monospace;">size() </span>method as obsolete. It appears that methods or variables ending in <span class="ec-lmtt-10" style="font-family: monospace,monospace;">component</span>, which
have a <span class="ec-lmtt-10" style="font-family: monospace,monospace;">size() </span>method called on it such as <span class="ec-lmtt-10" style="font-family: monospace,monospace;">component().size() </span>will trigger this finding. There is a
deprecated <span class="ec-lmtt-10" style="font-family: monospace,monospace;">size </span>method which is a part of the awt <span class="ec-lmtt-10" style="font-family: monospace,monospace;">Component </span>class. We speculate that this false positive is
a result of text searches that assume any <span class="ec-lmtt-10" style="font-family: monospace,monospace;">component.size() </span>is an awt <span class="ec-lmtt-10" style="font-family: monospace,monospace;">Component </span>whether it is or
not.
</p>
<!-- l. 7 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Another class of false positives is particularly bothersome. It appears that if any version of a method carries the
<span class="ec-lmtt-10" style="font-family: monospace,monospace;">@Deprecated </span>annotation, then all overloads of that method will be considered deprecated by this scanner. Ideally,
we would like to see the scanner take into account the type / order of parameters and only flag the invocations of
the method that were actually annotated as deprecated.
</p>
<!-- l. 9 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Lastly, we have seen uses of <span class="ec-lmtt-10" style="font-family: monospace,monospace;">toString </span>marked as obsolete. There did appear to be a bit more context awareness
with these findings, as the variable names were allowed a wider degree of variation. The commonality in these
<span class="ec-lmtt-10" style="font-family: monospace,monospace;">toString </span>findings was the class of the variable. In all cases they were of class <span class="ec-lmtt-10" style="font-family: monospace,monospace;">Permission</span>. There is an interface in
Java named <span class="ec-lmtt-10" style="font-family: monospace,monospace;">Permission </span>which has been deprecated (<span class="ec-lmtt-10" style="font-family: monospace,monospace;">java.security.acl.Permission</span>). We speculate that all
objects declared to be of a class named <span class="ec-lmtt-10" style="font-family: monospace,monospace;">Permission </span>which call <span class="ec-lmtt-10" style="font-family: monospace,monospace;">toString </span>will be flagged regardless of whether or not
they implement the <span class="ec-lmtt-10" style="font-family: monospace,monospace;">java.security.acl.Permission </span>interface.
</p>
<!-- l. 11 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   There are likely other false positives to be found. Although this scanner can provide some useful information, we
hope to see it updated in the future to incorporate more type checking.
                                                                                         
                                                                                         
</p>
   

<h3 class="sectionHead" style="line-height: 1.2; font-size: 1.5157em;"><a id="x1-2000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>References</h3>


<!-- l. 49 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">    
</p>


<dl class="thebibliography"><dt class="thebibliography" id="X0-swatips" style="float: left; clear: left; margin-right: 1em;">
[1]  
</dt><dd class="thebibliography" id="bib-1" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon Hood, ed. <span class="uline" style="text-decoration: underline;">SwATips</span>. <a class="url" href="https://www.SwATips.com/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.SwATips.com/</span></a>.</p></dd></dl>

 

]]></description>
	</item>
	<item>
		<title>Ada Unchecked Conversions</title>
		<link>https://www.SwATips.com/articles/20230410.html</link>
		<pubDate>Mon, 10 Apr 2023 00:00:00 -0500</pubDate>
<description><![CDATA[

<p style="margin-top: 0; margin-bottom: 0;"><a href="/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/swatips.svg" width="120" alt="SwATips" style="border-top: 0; border-left: 0; border-right: 0;"/></a>| <a href="articles/20230410.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">pdf</a> | <a rel="license" href="http://creativecommons.org/licenses/by/4.0/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/by.svg" width="60" height="21" alt="CC-BY" style="border-top: 0; border-left: 0; border-right: 0;"/></a></p>


<div class="maketitle" style="margin-top: 1em; text-align: center; margin-bottom: 2em;">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead" style="text-align: center;"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a id="x1-3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1</a>]<br/>
</h2>
<div class="author" style="text-align: center;"><span class="ec-lmr-12" style="font-size: 120%;">Jon Hood</span></div><br/>
<div class="date" style="text-align: center;"><span class="ec-lmr-12" style="font-size: 120%;">Monday 10</span><sup class="textsuperscript"><span class="ec-lmr-9" style="font-size: 90%;">th</span></sup><span class="ec-lmr-12" style="font-size: 120%;"> April, 2023</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead" id="ada-unchecked-conversions"><span class="titlemark">1   </span> <a id="x1-10001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Ada Unchecked Conversions</h3>


<!-- l. 44 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;"><span class="ec-lmr-8" style="font-size: 80%;">Updated Friday 12</span><sup class="textsuperscript"><span class="ec-lmr-9" style="font-size: 90%;">th</span></sup><span class="ec-lmr-8" style="font-size: 80%;"> May, 2023</span>
</p>
<!-- l. 1 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   The SwA team lives in a privileged area. If you throw a rock out of your window, chances are that you’ll hit a C,
C++, or C# developer. But it takes a tactical nuke to pinpoint a good Ada developer here. Because of this,
several companies have projects that are built partially in Ada and partially in C++. Interactions
between these components often cause security issues, but the most misunderstood of them all is the
<span class="ec-lmtt-10" style="font-family: monospace,monospace;">unchecked_conversion</span>.
</p>
<!-- l. 3 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   When evaluating software, we often flag the use of <span class="ec-lmtt-10" style="font-family: monospace,monospace;">unchecked_conversion </span>for multiple reasons:
</p>
     

<ul class="itemize1">
<li class="itemize">Sending dynamic memory outside of the scope or locality of where it is instantiated is a violation of
RAII programming.
</li>
<li class="itemize">You must be able to know the exact structure all endpoints that access the memory object are expecting.</li></ul>


<!-- l. 9 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">
</p>
   

<h4 class="subsectionHead" id="a-violation-of-raii"><span class="titlemark">1.1   </span> <a id="x1-20001.1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>A Violation of RAII</h4>


<!-- l. 10 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">The first issue has to do with RAII principles. When memory objects are created in one locality of the code and
used in another, the area of code that created the memory object is no longer in charge of making sure that
object is cleaned up. If it does clean up the memory before exiting, the unmanaged locality of code
may still be trying to use it! This would cause issues with race conditions, accessing memory that has
already been freed, or even accessing new memory objects that are now in that location of memory (and
potentially should not be accessible by the other locality of code, ex: the Dirty Cow vulnerability for
Linux).
</p>
<!-- l. 12 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Failing to enforce memory cleanup at the unmanaged endpoint would also result in memory leaks. This could
cause crashes and degraded performance over time.
</p>
<!-- l. 14 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead" id="a-violation-of-portability"><span class="titlemark">1.2   </span> <a id="x1-30001.2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>A Violation of Portability</h4>


<!-- l. 15 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Code that does not behave the same across platforms violates the concept of portability. This is often the case when
<span class="ec-lmtt-10" style="font-family: monospace,monospace;">unchecked </span>conversions and pointers are used. When performing an unchecked data access on memory, the developer
must know: </p>


<ul class="itemize1">     
<li class="itemize">the endianness of the unmanaged portions of the code
</li>
<li class="itemize">the compiler options used
</li>
<li class="itemize">that updates to the unmanaged portion of code will not violate the contract of how the memory should
be stored</li></ul>

                                                                                         
                                                                                         

<!-- l. 22 -->
<p class="indent" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   Consider an Ada program sending a simple data structure to a C program consisting of a character and an
integer as defined in Listing <a href="#x1-3001r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1<!-- tex4ht:ref: lst:20230410:struct  --></a>. The character takes up 1 byte and the integer takes up 4 bytes. So, in the Ada code,
we convert the first byte to the character and the next 4 bytes as the integer (accessing both with the
<span class="ec-lmtt-10" style="font-family: monospace,monospace;">unchecked_conversion </span>capability. But is that how it really works? </p>
<!-- l. 23 -->


<p id="-simple-structure-example" style="margin-bottom: 0; margin-top: 1em;"><a id="x1-3001r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>
<a id="x1-3002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>   
</p>
<pre class="lstlisting" id="listing-1" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-3003r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">struct</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">A</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-3004r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">{</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-3005r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">char</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">a;</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-3006r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">int</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">b;</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-3007r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">}</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">tmpA </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">= </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">{</span><span class="ts1-lmtt9-" style="font-size: 90%;">'</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">a</span><span class="ts1-lmtt9-" style="font-size: 90%;">'</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">, </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">1};</span></span></pre>


<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 1: </span><span class="content">Simple Structure Example</span></figcaption>
<!-- tex4ht:label?: x1-3007r1  -->


<!-- l. 31 -->
<p class="indent" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   Of course not! By default, most compilers (like GCC) pad each data type to the next memory alignment. The
character takes up 1 byte, then 3 bytes of padding are added before the 4 bytes that define the integer. If you were
to run <span class="ec-lmtt-10" style="font-family: monospace,monospace;">sizeof(tmpA); </span>in any modern GCC compiler, the result would be 8 bytes. Or at least, that’s the default
case. If you were to add the <span class="ec-lmtt-10" style="font-family: monospace,monospace;">__attribute__((packed)) </span>GCC directive to the struct, use <span class="ec-lmtt-10" style="font-family: monospace,monospace;">#pragma
</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">pack</span>, or compile with <span class="ec-lmtt-10" style="font-family: monospace,monospace;">-fpack-struct</span>, the <span class="ec-lmtt-10" style="font-family: monospace,monospace;">sizeof(tmpA) </span>becomes 5 bytes, misaligning the integer
value with memory so that it takes two memory operations to read the integer but taking up less
memory.
</p>
<!-- l. 33 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead" id="fixes"><span class="titlemark">1.3   </span> <a id="x1-40001.3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Fixes</h4>


<!-- l. 34 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Solutions that do not use <span class="ec-lmtt-10" style="font-family: monospace,monospace;">unchecked </span>memory access are preferred. This often requires the code to
be rearchitected to abide by RAII programming concepts. In lieu of fixing the code, a contract can
be documented that guarantees that all parties involved will abide by a particular memory sharing
structure.
</p>
<!-- l. 36 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead" id="conclusion"><span class="titlemark">1.4   </span> <a id="x1-50001.4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Conclusion</h4>


<!-- l. 37 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">When performing unchecked conversions, using external memory access, or violating RAII with two distinct
functional objects, a contract should be established. Part of that contract is a guarantee about the
memory structure of what is being shared. That contract should include architecture information,
memory packing, and even the flags and versions of compilers used to build the memory structures.
Creators of this documentation should ask themselves, “What prevents someone from compiling this code
with options like <span class="ec-lmtt-10" style="font-family: monospace,monospace;">-fpack-struct</span>?” “How are memory structures updated in newer versions of the
software?” and “What is the enforcement mechanism to ensure that the code is only built in the approved
way?”
                                                                                         
                                                                                         
</p>
   

<h3 class="sectionHead" id="references"><a id="x1-60001.4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>References</h3>


<!-- l. 49 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">    
</p>


<dl class="thebibliography"><dt class="thebibliography" id="X0-swatips" style="float: left; clear: left; margin-right: 1em;">
[1]  
</dt><dd class="thebibliography" id="bib-1" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon Hood, ed. SwATips.     <a class="url" href="https://www.SwATips.com/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.SwATips.com/</span></a>.</p></dd></dl>

 

]]></description>
	</item>
