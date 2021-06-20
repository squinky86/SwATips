	<item>
		<title>Living off the Land</title>
		<link>https://www.SwATips.com/articles/20210621.html</link>
		<pubDate>Mon, 21 Jun 2021 00:00:00 -0500</pubDate>
<description><![CDATA[

<p style="margin-top: 0; margin-bottom: 0;">Return to <a href="/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">SwATips</a> | <a href="articles/20210621.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">pdf</a> | <a rel="license" href="http://creativecommons.org/licenses/by/4.0/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/by.svg" width="60" height="21" alt="CC-BY" style="border-top: 0; border-left: 0; border-right: 0;"/></a></p>


<div class="maketitle" style="margin-top: 1em; text-align: center; margin-bottom: 2em;">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead" style="text-align: center;"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a href="#cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2</a>]<br/>
Generated Sunday 20<sup class="textsuperscript">th</sup> June, 2021</h2>
<div class="author" style="text-align: center;"><span class="rm-lmr-12" style="font-size: 120%;">Jon Hood</span></div><br/>
<div class="date" style="text-align: center;"><span class="rm-lmr-12" style="font-size: 120%;">Monday 21</span><sup class="textsuperscript"><span class="rm-lmr-9" style="font-size: 90%;">st</span></sup><span class="rm-lmr-12" style="font-size: 120%;"> June, 2021</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead"><span class="titlemark">1   </span> <a id="x1-10001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Living off the Land</h3>


<!-- l. 1 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Living off the Land (LotL) refers to using the tools, scripts, libraries, and binaries that are native
and pre-installed with an environment.[<a href="#cite.0@20210621:rains2020cybersecurity" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">6</a>, p. 299] Attackers use the existing tools of their exploited
environment to decrease their footprint and avoid detection, often blending in by using legitimate
tools and administrative functions in a malicious way.[<a href="#cite.0@20210621:calder2020cyber" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1</a>, p. 45] Nevertheless, developers can use LotL
concepts to decrease the attackable footprint of their software as a mitigation strategy against attacks as
well!
</p>
<!-- l. 3 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.1   </span> <a id="x1-20001.1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>LotL: An Attacker’s Perspective</h4>


<!-- l. 5 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">When attacking an environment, penetration testing teams often attempt to take an inventory of
what is available to see what can be utilized to establish persistence and pivot in the environment
without detection. If the attacker has to install specialized tools and packages, intrusion detection and
prevention systems can be configured to look for those packages as part of a defense-in-depth mitigation
strategy.
</p>
<!-- l. 7 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.2   </span> <a id="x1-30001.2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>LotL: A Defender’s Perspective</h4>


<!-- l. 9 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Defensive (blue) teams should be familiar with the attacks and threats posed by penetration testing (red) teams. In
2013, the DoD used the following definition of Software Assurance: “the level of confidence that software functions
as intended and is free of vulnerabilities, either intentionally or unintentionally designed or inserted as part of the
software, throughout the life cycle.”[<a href="#cite.0@20210621:ndaa2013" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">5</a>, p. 255 §933.e.2] In 2017, the Office for the Secretary of Defense clarified the
definition of “functions as intended” to mean “<i>only</i> functions as intended” by showing confidently that the software
meets functionality and test coverage requirements and also “does not perform unrequired functions.”[<a href="#cite.0@20210621:marien2017" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">4</a>, p. 7] Since
2017, the caveat “and only as intended” has been codified as part of the DoD’s definition of Software Assurance.[<a href="#cite.0@20210621:hurt2017" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">3</a>,
p. 2]
</p>
<!-- l. 11 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Developers are often tempted by heavyweight frameworks that provide sundry capabilities. For low-assurance
tasks, these frameworks permit rapid development and deployment of solutions. In tactical environments, these
bloated dependencies are much more difficult to maintain. Large frameworks must be maintained and reviewed for
CVEs and security updates in their deployed environments, even when security findings affect areas of the
framework that are not utilized by the solution.
</p>
<!-- l. 13 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.3   </span> <a id="x1-40001.3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>LotL In Practice</h4>


<!-- l. 15 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Recently, one particular application provided a framework that used libzip, zlib, 7-Zip, and the System.IO.Compression
ZipArchive routines for reading in compressed files at different parts of the application. During the Software
Assurance scans, we were able to create a payload using the Zip Slip vulnerability to upload and execute any
payload we needed. During postmortem analysis, the developers cleaned up the vulnerability that was used, but
forgot to verify that another location of the code used a vulnerable version of 7-Zip that could stage the same
payload!
</p>
<!-- l. 17 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.4   </span> <a id="x1-50001.4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Mitigations</h4>

                                                                                         
                                                                                         

<!-- l. 19 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Mitigations to attackers that attempt LotL techniques involve making sure that the land an attacker would get is
insufficient for staging more advanced attacks. When an attacker only gets access to a minimalist, sandboxed
island, there isn’t enough land to live on. They must either be noisy, terraforming the land into a new
environment and risking detection, or silently move on to another, more vulnerable environment to avoid
detection.
</p>
<!-- l. 21 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Some additional information to consider: </p>


<ul class="itemize1">     
<li class="itemize">If installing a webserver, determine the languages web applications are written in. If there are no perl,
PHP, Ruby, or .NET applications, then why install those frameworks to begin with?
</li>     
<li class="itemize">Watch for additional tools being installed. Why should the sandboxed web account have access to
netcat, telnet, or the entire suite of tools? Why is there a compiler installed on the server?
</li>     
<li class="itemize">If a service does not need to be touched by a user, does it make sense to give that service its own
sandbox and account with access only to the application that needs it to run?</li></ul>


<!-- l. 28 -->
<p class="indent" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   A defender should follow the least-privilege and minimum functionality practices when developing software. By
refusing to give an attacker much land to live on, developers reduce their exposure space and discourage malicious
activities. As a byproduct of using minimal frameworks and dependencies, maintenance becomes easier, particularly
on disconnected and tactical systems.
</p>
<!-- l. 30 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Containers that provide only the needed functionality should be preferred over monolithic containers that
provide entire operating systems and environments. By sandboxing user execution, an attacker that successfully gets
a foothold into an application is rewarded with their very own tiny sandbox to play in, while non-containerized,
multi-user execution often provides attackers with the keys to the entire kingdom. Compromise is not a fun topic to
consider, but risk prevention is not a binary, pwned-or-not decision. I’d prefer that my software not be compromised,
but if it should become impaired, I’d rather the malicious attacker only be able to steal the sandbox rather than the
entire kingdom!
</p>
<!-- l. 32 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   If you give a crook your sandbox, they’ll defecate in your sand. But if you give a crook your kingdom, they’ll
usurp your entire domain.
                                                                                         
                                                                                         
</p>
   

<h3 class="sectionHead"><a id="x1-60001.4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>References</h3>


<!-- l. 45 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">    
</p>


<dl class="thebibliography"><dt id="X0-20210621:calder2020cyber" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[1]  
</dt><dd id="bib-1" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 45 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20210621:calder2020cyber" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Alan Calder. <span class="rm-lmri-10" style="font-style: italic;">The Cyber Security Handbook. Prepare for, respond to and recover from cyber attacks</span>. IT
Governance Publishing Ltd, 2020. <span class="small-caps" style="font-variant: small-caps;">isbn</span>: 978-1-78778-261-7.
</p>    
</dd>
<dt id="X0-swatips" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[2]  
</dt><dd id="bib-2" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 45 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon Hood, ed. <span class="rm-lmri-10" style="font-style: italic;">SwATips</span>. <a href="https://www.SwATips.com/" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.SwATips.com/</span></a>.
</p>    
</dd>
<dt id="X0-20210621:hurt2017" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[3]  
</dt><dd id="bib-3" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 45 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20210621:hurt2017" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Thomas Hurt. <span class="rm-lmri-10" style="font-style: italic;">Achieving DoD Software Assurance (SwA)</span>. Tech. rep. Springfield, VA: 20<span class="cmmi-7" style="font-size: 70%; font-style: italic;">th</span> Annual NDIA
Systems Engineering Conference, Oct. 2017. <span class="small-caps" style="font-variant: small-caps;">url</span>: <a href="https://ndiastorage.blob.core.usgovcloudapi.net/ndia/2017/systems/Thursday/Track1/19911_Hurt.pdf" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://ndiastorage.blob.core.usgovcloudapi.net/ndia/2017/systems/Thursday/Track1/19911_Hurt.pdf</span></a>.
</p>    
</dd>
<dt id="X0-20210621:marien2017" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[4]  
</dt><dd id="bib-4" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 45 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20210621:marien2017" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>John R. Marien and Robert A. Martin. <span class="rm-lmri-10" style="font-style: italic;">Incorporating Software Assurance into Department of Defense
</span><span class="rm-lmri-10" style="font-style: italic;">Acquisition Contracts</span>. Tech. rep. Department of Defense (DoD) Software Assurance (SwA) Community
of Practice (CoP) Contract Language Working Group, 2017. <span class="small-caps" style="font-variant: small-caps;">url</span>: <a href="https://rt.cto.mil/wp-content/uploads/2019/06/Incorporating-SwA-Contracts-2017-11-15.pdf" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://rt.cto.mil/wp-content/uploads/2019/06/Incorporating-SwA-Contracts-2017-11-15.pdf</span></a>.
</p>    
</dd>
<dt id="X0-20210621:ndaa2013" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[5]  
</dt><dd id="bib-5" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 45 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20210621:ndaa2013" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>NATIONAL DEFENSE AUTHORIZATION ACT FOR FISCAL YEAR 2013. <span class="rm-lmri-10" style="font-style: italic;">Public Law 112–239</span>.
Jan. 2013. <span class="small-caps" style="font-variant: small-caps;">url</span>: <a href="https://www.congress.gov/112/plaws/publ239/PLAW-112publ239.pdf" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.congress.gov/112/plaws/publ239/PLAW-112publ239.pdf</span></a>.
</p>    
</dd>
<dt id="X0-20210621:rains2020cybersecurity" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[6]  
</dt><dd id="bib-6" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 45 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20210621:rains2020cybersecurity" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Tim Rains. <span class="rm-lmri-10" style="font-style: italic;">Cybersecurity Threats, Malware Trends, and Strategies. Learn to mitigate exploits, malware,
</span><span class="rm-lmri-10" style="font-style: italic;">phishing, and other social engineering attacks</span>. Packt Publishing, 2020. <span class="small-caps" style="font-variant: small-caps;">isbn</span>: 978-1-80020-589-5.</p></dd></dl>

 

]]></description>
	</item>
	<item>
		<title>Secure Compilation</title>
		<link>https://www.SwATips.com/articles/20210614.html</link>
		<pubDate>Mon, 14 Jun 2021 00:00:00 -0500</pubDate>
<description><![CDATA[

<p style="margin-top: 0; margin-bottom: 0;">Return to <a href="/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">SwATips</a> | <a href="articles/20210614.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">pdf</a> | <a rel="license" href="http://creativecommons.org/licenses/by/4.0/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/by.svg" width="60" height="21" alt="CC-BY" style="border-top: 0; border-left: 0; border-right: 0;"/></a></p>


<div class="maketitle" style="margin-top: 1em; text-align: center; margin-bottom: 2em;">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead" style="text-align: center;"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a href="#cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">5</a>]<br/>
Generated Thursday 10<sup class="textsuperscript">th</sup> June, 2021</h2>
<div class="author" style="text-align: center;"><span class="rm-lmr-12" style="font-size: 120%;">Richard Ford</span></div><br/>
<div class="date" style="text-align: center;"><span class="rm-lmr-12" style="font-size: 120%;">Monday 14</span><sup class="textsuperscript"><span class="rm-lmr-9" style="font-size: 90%;">th</span></sup><span class="rm-lmr-12" style="font-size: 120%;"> June, 2021</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead"><span class="titlemark">1   </span> <a id="x1-10001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Secure Compilation</h3>


<!-- l. 1 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Ordinary compilers aim to provide correct compilation based on the rules of the source language. Most language
standards allow the compiler to perform optimizations provided they follow the “as if” rule: that the external
interactions of the program are the same as if the compiler had not optimized but rigidly followed the language
abstract model of execution. In addition, refinement is allowed. The source language may allow several different
ways that the program may be executed. The compiler is considered correct if the target code behaves in one of
those ways.
</p>
<!-- l. 3 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Security problems arise because attackers do not play by the source language rules.[<a href="#cite.0@20210614:sidhpurwala" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">7</a>, <a href="#cite.0@20210614:dsilva" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">4</a>] </p>


<ul class="itemize1">     
<li class="itemize">A compromised operating system can inspect the memory of a running program. So, memory locations
formerly occupied by out-of-scope function variables can be inspected to see the possibly sensitive data
they held.
</li>     
<li class="itemize">The timing behavior of the computation can be used to leak sensitive information.</li></ul>


<!-- l. 9 -->
<p class="indent" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   The emerging field of secure compilation seeks to define what it means for compilation to be secure.[<a href="#cite.0@20210614:busi" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2</a>, <a href="#cite.0@20210614:patrignani" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">6</a>] There
is much ongoing research on secure compilation.
</p>
<!-- l. 11 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Whereas most compiler correctness research has been on whole-program compilation, the secure compilation
studies use program fragments (called components) which are linked with a context. The context is used to model
attackers. The behavior of a component is characterized by the set of traces (sequences of events) it may produce.
Two components are considered contextually equivalent if, when combined with the same arbitrary context, they
produced the same trace.
</p>
<!-- l. 13 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   A key concept mentioned in many of the papers is that of fully-abstract compilation. A compilation is fully
abstract if it has two properties:
</p>
     

<ol class="enumerate1" style="list-style-type: decimal;">
<li class="enumerate" id="x1-1002x1">     
<i>Contextually equivalence preservation:</i> if two components are contextually equivalent at the source
level, then their compiled forms are also contextually equivalent.
</li>     
<li class="enumerate" id="x1-1004x2">
<i>Contextually equivalent reflection:</i> if the compiled form of two components are contextually equivalent,
then they are also contextually equivalent at the source.</li></ol>


<!-- l. 19 -->
<p class="indent" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   Because fully abstract compilation involves quantification over contexts, it is difficult to prove. An alternate
approach is to focus on properties and hyperproperties.[<a href="#cite.0@20210614:clarkson" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">3</a>]
</p>
<!-- l. 21 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   A program property can be represented by the set of traces that satisfy that property. The language semantics
specify the set of allowable traces. A program will satisfy a property if its set of traces (as defined by the language)
is a subset of the property’s traces.
</p>
<!-- l. 23 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   A correct compiler, because of refinement or optimization, is allowed to produce a target program which will
only produce a subset of those traces. But if the source program satisfied the property, the target program will also
(assuming no attacks).
</p>
<!-- l. 25 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Whereas a property is characterized by a set of traces, a hyperproperty is a set of sets of traces. Hyperproperties
can express requirements that cannot be expressed using only properties. For example, non-interference can be
expressed by saying that for every trace involving a mix of low and high inputs and outputs there is another trace
with the high inputs and outputs deleted, that has the same low inputs and outputs (thus the low inputs and
outputs are not influenced by the high inputs or outputs).
</p>
<!-- l. 27 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   The goal of secure compilation is not to remove security vulnerabilities from source programs, but to ensure that
no vulnerabilities are introduced. Secure compilation, whether to achieve full abstraction or to preserve
some specified properties in the face of attacks is not possible unless the target language has some
means of protection. In particular, protecting data-in-use requires hardware protection mechanism.
Some example hardware mechanisms that have been studied in regard to secure compilation are:[<a href="#cite.0@20210614:busi" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2</a>, <a href="#cite.0@20210614:patrignani" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">6</a>]
</p>

                                                                                         
                                                                                         
     

<ul class="itemize1">
<li class="itemize">Typed-assembly language
</li>     
<li class="itemize">Capability Machines (CHERI)
</li>     
<li class="itemize">Protected Module Architectures (PMA): e.g., SGX
</li>     
<li class="itemize">Micro-policies (CRASH/SAFE, or Dover CoreGuard)</li></ul>


<!-- l. 35 -->
<p class="indent" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   Most of the secure compilation theories have been based on trace events that are the same for source and target
language. But recent work has generalized this theory to use relations to relate source and target event
traces.[<a href="#cite.0@20210614:abate" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1</a>]
</p>
<!-- l. 37 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Current software development practice targets platforms that do not have the required hardware protection
mechanisms and uses compilers that strive to be correct but that are unaware of the additional security
requirements. Here are some possible recommendations to avoid vulnerabilities: </p>


<ul class="itemize1">     
<li class="itemize">Promote use of hardware protections that are currently available (e.g., SGX and CoreGuard) but not
currently being used.
</li>     
<li class="itemize">Formulate and propose security contracts for programming languages and implement them in some
open-source compilers. For example, an annotation could be added to the declaration of sensitive data.
The compiler could then erase the data as soon as it goes out of scope.
</li>     
<li class="itemize">Use software scanners to detect vulnerabilities and try to use existing compiler features to minimize
exposure.</li></ul>

                                                                                         
                                                                                         
   

<h3 class="sectionHead"><a id="x1-20001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>References</h3>


<!-- l. 45 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">    
</p>


<dl class="thebibliography"><dt id="X0-20210614:abate" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[1]  
</dt><dd id="bib-1" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 45 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20210614:abate" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Carmine Abate et al. <span class="rm-lmri-10" style="font-style: italic;">Trace-Relating Compiler Correctness and Secure Compilation</span>. 2020. arXiv: <a href="https://arxiv.org/abs/1907.05320" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">1907.
</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">05320 [cs.PL]</span></a>.
</p>    
</dd>
<dt id="X0-20210614:busi" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[2]  
</dt><dd id="bib-2" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 45 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20210614:busi" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Matteo  Busi  and  Letterio  Galletta.  “A  brief  tour  of  formally  secure  compilation”.  In:  <span class="rm-lmri-10" style="font-style: italic;">3rd  Italian
</span><span class="rm-lmri-10" style="font-style: italic;">Conference on Cyber Security, ITASEC 2019</span>. Vol. 2315. CEUR-WS. 2019.
</p>    
</dd>
<dt id="X0-20210614:clarkson" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[3]  
</dt><dd id="bib-3" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 45 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20210614:clarkson" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Michael  R.  Clarkson  and  Fred  B.  Schneider.  “Hyperproperties”.  In:  <span class="rm-lmri-10" style="font-style: italic;">21st IEEE Computer Security
</span><span class="rm-lmri-10" style="font-style: italic;">Foundations Symposium</span>. June 2008, pp. 51–65.
</p>    
</dd>
<dt id="X0-20210614:dsilva" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[4]  
</dt><dd id="bib-4" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 45 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20210614:dsilva" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Vijay  D’Silva,  Mathias  Payer,  and  Dawn  Song.  “The  Correctness-Security  Gap  in  Compiler
Optimization”. In: <span class="rm-lmri-10" style="font-style: italic;">2015 IEEE Security and Privacy Workshops</span>. 2015, pp. 73–87. <span class="small-caps" style="font-variant: small-caps;">doi</span>: <a href="https://doi.org/10.1109/SPW.2015.33" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">10.1109/SPW.
</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">2015.33</span></a>.
</p>    
</dd>
<dt id="X0-swatips" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[5]  
</dt><dd id="bib-5" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 45 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon Hood, ed. <span class="rm-lmri-10" style="font-style: italic;">SwATips</span>. <a href="https://www.SwATips.com/" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.SwATips.com/</span></a>.
</p>    
</dd>
<dt id="X0-20210614:patrignani" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[6]  
</dt><dd id="bib-6" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 45 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20210614:patrignani" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Marco Patrignani, Amal Ahmed, and Dave Clarke. “Formal Approaches to Secure Compilation: A
Survey of Fully Abstract Compilation and Related Work”. In: <span class="rm-lmri-10" style="font-style: italic;">ACM Comput. Surv. </span>51.6 (Feb. 2019).
<span class="small-caps" style="font-variant: small-caps;">issn</span>: 0360-0300. <span class="small-caps" style="font-variant: small-caps;">doi</span>: <a href="https://doi.org/10.1145/3280984" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">10.1145/3280984</span></a>. <span class="small-caps" style="font-variant: small-caps;">url</span>: <a href="https://doi.org/10.1145/3280984" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://doi.org/10.1145/3280984</span></a>.
</p>    
</dd>
<dt id="X0-20210614:sidhpurwala" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[7]  
</dt><dd id="bib-7" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 45 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20210614:sidhpurwala" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Huzaifa Sidhpurwala. “Security flaws caused by compiler optimizations”. In: <span class="rm-lmri-10" style="font-style: italic;">Red Hat Blog </span>(2019). <span class="small-caps" style="font-variant: small-caps;">url</span>:
<a href="https://www.redhat.com/en/blog/security-flaws-caused-compiler-optimizations" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.redhat.com/en/blog/security-flaws-caused-compiler-optimizations</span></a>.</p></dd></dl>

 

]]></description>
	</item>
	<item>
		<title>Side-Channel Attacks</title>
		<link>https://www.SwATips.com/articles/20210524.html</link>
		<pubDate>Mon, 24 May 2021 00:00:00 -0500</pubDate>
<description><![CDATA[

<p style="margin-top: 0; margin-bottom: 0;">Return to <a href="/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">SwATips</a> | <a href="articles/20210524.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">pdf</a> | <a rel="license" href="http://creativecommons.org/licenses/by/4.0/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/by.svg" width="60" height="21" alt="CC-BY" style="border-top: 0; border-left: 0; border-right: 0;"/></a></p>


<div class="maketitle" style="margin-top: 1em; text-align: center; margin-bottom: 2em;">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead" style="text-align: center;"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a href="#cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1</a>]<br/>
Generated Monday 24<sup class="textsuperscript">th</sup> May, 2021</h2>
<div class="author" style="text-align: center;"><span class="rm-lmr-12" style="font-size: 120%;">Jon Hood</span></div><br/>
<div class="date" style="text-align: center;"><span class="rm-lmr-12" style="font-size: 120%;">Monday 24</span><sup class="textsuperscript"><span class="rm-lmr-9" style="font-size: 90%;">th</span></sup><span class="rm-lmr-12" style="font-size: 120%;"> May, 2021</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead"><span class="titlemark">1   </span> <a id="x1-10001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Side-Channel Attacks</h3>


<!-- l. 4 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">The insider threat is one of the most difficult to find. I thought I’d lay out some ways in which we’ve found
side-channel attacks (CWE-514) in actual systems that we have evaluated. They include: </p>


<ul class="itemize1">     
<li class="itemize">Inadvertent data through a backdoor
</li>     
<li class="itemize">Purposeful use of hard drive architectures to hide files
</li>     
<li class="itemize">Using seemingly benign documents to deliver an evil payload</li></ul>


<!-- l. 11 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.1   </span> <a id="x1-20001.1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Development Backdoors</h4>


<!-- l. 12 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;"><span class="paragraphHead" style="margin-top: 2em; font-weight: bold;"><a id="x1-30001.1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><span class="rm-lmbx-10" style="font-weight: bold;">Developers often leave backdoors into a system.</span></span>
This is sometimes left-over debug access meant to speed up development (CWE-489). When these backdoors are
deployed in the wild, they become attack vectors wielded to access and sneak data out of a system without any
visibility in logs and access control mechanisms. But this article primarily deals with the intentional side
channels:
</p>
<!-- l. 14 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.2   </span> <a id="x1-40001.2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Malicious Hardware</h4>


<!-- l. 15 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;"><span class="paragraphHead" style="margin-top: 2em; font-weight: bold;"><a id="x1-50001.2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><span class="rm-lmbx-10" style="font-weight: bold;">Hard drive architectures and other removable media can be exploited to provide a side
</span><span class="rm-lmbx-10" style="font-weight: bold;">channel.</span></span>
Suppose that you want to send a sensitive file to a malicious entity, but you don’t want that file to
show up in any filesystem scans or perfunctory data scans of the media. The data may be hidden
outside of filesystem control. In *nix systems, the <span class="ec-lmtt-10" style="font-family: monospace,monospace;">dd </span>command can be used to hide data outside of the
filesystem. Assuming the removable device is /dev/sdb (it doesn’t even have to be partitioned) and
it has 1465149168 sectors, an attacker can run “<span class="ec-lmtt-10" style="font-family: monospace,monospace;">dd of=/dev/sdb bs=512 skip=1465140001 &lt; </span><span class="ts1-lmtt10-">'</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">I
</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">am a sneaky little string!</span><span class="ts1-lmtt10-">'</span>” to sneak their message onto the hard drive. To retrieve the string,
the recipient can simply “<span class="ec-lmtt-10" style="font-family: monospace,monospace;">dd if=/dev/sdb bs=512 skip=1465140001 count=30</span>” and retrieve the
text.
</p>
<!-- l. 17 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   This becomes especially hidden when:
</p>
     

<ol class="enumerate1" style="list-style-type: decimal;">
<li class="enumerate" id="x1-5002x1">     
The filesystem does not have anything else stored at the sectors starting at 1465140001
</li>     
<li class="enumerate" id="x1-5004x2">
There is no filesystem provisioned that includes the sectors starting at 1465140001
</li>     
<li class="enumerate" id="x1-5006x3">
A Host Protected Area (HPA) is set so that the operating system can’t see anything past sector
1465140000 (“<span class="ec-lmtt-10" style="font-family: monospace,monospace;">hdparm -N p1465140000 /dev/sdb &amp;&amp; reboot</span>”)</li></ol>

                                                                                         
                                                                                         

<!-- l. 24 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.3   </span> <a id="x1-60001.3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Malicious Software</h4>


<!-- l. 25 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;"><span class="paragraphHead" style="margin-top: 2em; font-weight: bold;"><a id="x1-70001.3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><span class="rm-lmbx-10" style="font-weight: bold;">Seemingly benign files can hide an attacker’s payload.</span></span>
Don’t believe me? Then take the PDF or HTML version of this tip and run the commands in Listing <a href="#x1-7001r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1<!-- tex4ht:ref: lst:20210524:binary  --></a> against it
in cygwin! </p>
<!-- l. 26 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-7001r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-7002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>
   

<div class="lstlisting" id="listing-1" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-7003r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">$ </span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">cat</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> -v 20210524.pdf | grep "^%PAY:" | tail -c +6 | base64 -d &gt; sneaky.exe </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-7004r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">$ chmod +x sneaky.exe </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-7005r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">$ ./sneaky.exe</span>
<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 1:</span><span class="content">Hidden Binary in This File</span></figcaption><!-- tex4ht:label?: x1-7001r1  -->
   
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead"><a id="x1-80001.3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>References</h3>


<!-- l. 45 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">    
</p>


<dl class="thebibliography"><dt id="X0-swatips" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[1]  
</dt><dd id="bib-1" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 45 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon Hood, ed. <span class="rm-lmri-10" style="font-style: italic;">SwATips</span>. <a class="url" href="https://www.SwATips.com/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.SwATips.com/</span></a>.</p></dd></dl>

 

]]></description>
	</item>
	<item>
		<title>Secure Pseudo-Random Number Generation</title>
		<link>https://www.SwATips.com/articles/20210517.html</link>
		<pubDate>Mon, 17 May 2021 00:00:00 -0500</pubDate>
<description><![CDATA[

<p style="margin-top: 0; margin-bottom: 0;">Return to <a href="/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">SwATips</a> | <a href="articles/20210517.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">pdf</a> | <a rel="license" href="http://creativecommons.org/licenses/by/4.0/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/by.svg" width="60" height="21" alt="CC-BY" style="border-top: 0; border-left: 0; border-right: 0;"/></a></p>


<div class="maketitle" style="margin-top: 1em; text-align: center; margin-bottom: 2em;">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead" style="text-align: center;"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a href="#cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">4</a>]<br/>
Generated Monday 17<sup class="textsuperscript">th</sup> May, 2021</h2>
<div class="author" style="text-align: center;"><span class="rm-lmr-12" style="font-size: 120%;">James Shelton</span></div><br/>
<div class="date" style="text-align: center;"><span class="rm-lmr-12" style="font-size: 120%;">Monday 17</span><sup class="textsuperscript"><span class="rm-lmr-9" style="font-size: 90%;">th</span></sup><span class="rm-lmr-12" style="font-size: 120%;"> May, 2021</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead"><span class="titlemark">1   </span> <a id="x1-10001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Secure Pseudo-Random Number Generation</h3>


<!-- l. 1 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.1   </span> <a id="x1-20001.1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Definition</h4>


<!-- l. 2 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">As the name implies, pseudo-random number generation (PRNG) does not produce a truly random, indeterminate
value. The exact nature of this pseudo-randomness varies between languages and implementations, but essentially,
PRNG is accomplished via an algorithm that uses mathematical formulae or precalculated tables to produce
numerical values that appear random.[<a href="#cite.0@20210517:haahr" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">3</a>]
</p>
<!-- l. 4 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   However, a common characteristic of all methods of PRNG is that they are deterministic, meaning that
they require an initial seed in the form of another numerical value, and that, if the seed is known and
replicated exactly, the PRNG will produce the exact same results multiple times. These seeds can
take the form of literal values or variable representation of other, unrelated values, such as system
time.
</p>
<!-- l. 6 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Another property of PRNG is that the values it generates are periodic, meaning that, due to the finite amount
of pseudo-random values a given implementation can generate, the output will eventually begin to
repeat.
</p>
<!-- l. 8 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.2   </span> <a id="x1-30001.2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Examples</h4>


<!-- l. 9 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Most common programming languages have built-in PRNG implementations. The method <span class="ec-lmtt-10" style="font-family: monospace,monospace;">rand(</span>),
defined in the C Standard General Utilities Library, is perhaps the most basic PRNG function in the
C family, using a seed, provided by the developer as an argument to an earlier call to the method
<span class="ec-lmtt-10" style="font-family: monospace,monospace;">srand()</span>, to return an integer value between zero and the language-defined constant <span class="ec-lmtt-10" style="font-family: monospace,monospace;">RAND_MAX</span>.[<a href="#cite.0@20210517:cpp-rand" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">8</a>] C++11
expands upon these PRNG capabilities in its <span class="ec-lmtt-10" style="font-family: monospace,monospace;">&lt;random&gt; </span>header, which introduces numerous PRNG
implementations, from uniform distributors to algorithmic implementations of various mathematical
distributions.[<a href="#cite.0@20210517:cpp-random" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">6</a>]
</p>
<!-- l. 11 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Likewise, Java implements a <i>random</i> series of methods, found in the <span class="ec-lmtt-10" style="font-family: monospace,monospace;">Random </span>class of the <span class="ec-lmtt-10" style="font-family: monospace,monospace;">java.util.Random</span>
object, which function similarly to the C <span class="ec-lmtt-10" style="font-family: monospace,monospace;">rand() </span>function but can be specified to accept as a seeds and output
values of other numeric data types.[<a href="#cite.0@20210517:java" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">7</a>]
</p>
<!-- l. 13 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.3   </span> <a id="x1-40001.3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Issues</h4>


<!-- l. 14 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Because of the deterministic and periodic factors, the use of PRNG in a security context is typically discouraged, as
the requirement of a defined seed and the finite amount of possible outcomes means that, even if an
attacker is not aware of the initial condition, a supposedly random value can be realistically guessed by
the use of brute force alone. Still, PRNG has its place in such contexts, as it is generally considered
significantly more efficient and practical to implement than true random number generation (TRNG), as
TRNG extracts randomness from captured aspects of physical phenomena, such as radioactive decay or
atmospheric noise, which most commercially available computer hardware is simply not equipped to
do.
</p>
<!-- l. 16 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   An example of a use of PRNG in an identification and authentication scenario is the creation of a temporary
session ID for a user. The viability of this implementation is entirely dependent on the source of the seed value used
in the PRNG algorithm. One hypothetical source is a given user’s authentication ID, but this value is the same each
time the user logs in. Another option is that of the system time in Unix Time format, which, on one hand, is
guaranteed to change each second. On the other hand, an attacker could replicate a Unix Time string corresponding
with a date and time at which any given user is likely to be authenticating (say, a weekday at around 9:00<span class="small-caps" style="font-variant: small-caps;">AM</span>), and,
                                                                                         
                                                                                         
with enough luck, could potentially spoof the session ID of an active, verified user simply by correctly
guessing what time they logged on, a tactic that only increases in viability the more users a system
supports.
</p>
<!-- l. 18 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   From a software assurance perspective, in the event of scenario similar in scope to the previous example,
reported issues will usually adhere to a vulnerability description enumerated as CWE-337 or CWE-338,[<a href="#cite.0@20210517:cwe-337" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1</a>, <a href="#cite.0@20210517:cwe-338" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2</a>] the
former with respect to the use of the seeded value and the latter with respect to the PRNG function itself.
Occasionally, both will occur concurrently for the same instance.
</p>
<!-- l. 21 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.4   </span> <a id="x1-50001.4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Mitigations</h4>


<!-- l. 22 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">In general, the larger and more arbitrary the seed, the less likely the likely the PRNG implementation
can be exploited by an attacker. Or, at least, it would result in exploitation attempts taking longer
to accomplish, thus increasing the chance of the attack being noticed before the attacker succeeds.
Regardless, the very presence of a PRNG implementation is overwhelmingly likely to be documented as an
issue by a scan tool, but the security of such of an implementation can still be ensured through a
multilayered approach tailored to fit the specific context in which the pseudo-random value is being
used.
</p>
<!-- l. 24 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   In an authentication context, imposing a limit to the number of times a user can unsuccessfully
supply valid credentials and/or placing a restriction on subsequent attempts can mitigate attacks based
around exploiting PRNG to replicate a valid set of credentials or the privileges attached to a valid set of
credentials.
</p>
<!-- l. 26 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   In a cryptographic context, the use of algorithms whose PRNG has been sufficiently tested and independently
verified is the best way to mitigate potential issues. A list of random number generators approved for use in
cryptographic modules can be found in Annex C of the FIPS 140-2 publication from the Information Technology
Laboratory of the National Institute of Standards and Technology.[<a href="#cite.0@20210517:annexc" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">5</a>]
                                                                                         
                                                                                         
</p>
   

<h3 class="sectionHead"><a id="x1-60001.4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>References</h3>


<!-- l. 45 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">    
</p>


<dl class="thebibliography"><dt id="X0-20210517:cwe-337" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[1]  
</dt><dd id="bib-1" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 45 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20210517:cwe-337" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>CWE Content Team. “CWE-337: Predictable Seed in Pseudo-Random Number Generator (PRNG)”.
In: (2020). <span class="small-caps" style="font-variant: small-caps;">url</span>: <a href="https://cwe.mitre.org/data/definitions/337.html" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://cwe.mitre.org/data/definitions/337.html</span></a>.
</p>    
</dd>
<dt id="X0-20210517:cwe-338" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[2]  
</dt><dd id="bib-2" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 45 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20210517:cwe-338" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>CWE Content Team. “CWE-338: Use of Cryptographically Weak Pseudo-Random Number Generator
(PRNG)”. In: (2021). <span class="small-caps" style="font-variant: small-caps;">url</span>: <a href="https://cwe.mitre.org/data/definitions/338.html" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://cwe.mitre.org/data/definitions/338.html</span></a>.
</p>    
</dd>
<dt id="X0-20210517:haahr" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[3]  
</dt><dd id="bib-3" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 45 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20210517:haahr" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Mads Haahr. “Introduction to Randomness and Random Numbers”. In: <span class="rm-lmri-10" style="font-style: italic;">RANDOM.ORG </span>(2021). <span class="small-caps" style="font-variant: small-caps;">url</span>:
<a href="https://www.random.org/randomness/" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.random.org/randomness/</span></a>.
</p>    
</dd>
<dt id="X0-swatips" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[4]  
</dt><dd id="bib-4" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 45 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon Hood, ed. <span class="rm-lmri-10" style="font-style: italic;">SwATips</span>. <a href="https://www.SwATips.com/" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.SwATips.com/</span></a>.
</p>    
</dd>
<dt id="X0-20210517:annexc" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[5]  
</dt><dd id="bib-5" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 45 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20210517:annexc" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>National Institute of Standards and Technology. <span class="rm-lmri-10" style="font-style: italic;">Annex C: Approved Random Number Generators for
</span><span class="rm-lmri-10" style="font-style: italic;">FIPS PUB 140-2. Security Requirements for Cryptographic Modules</span>. Department of Commerce. 2019.
<span class="small-caps" style="font-variant: small-caps;">url</span>: <a href="https://csrc.nist.gov/CSRC/media/Publications/fips/140/2/final/documents/fips1402annexc.pdf" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://csrc.nist.gov/CSRC/media/Publications/fips/140/2/final/documents/fips1402annexc.pdf</span></a>.
</p>    
</dd>
<dt id="X0-20210517:cpp-random" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[6]  
</dt><dd id="bib-6" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 45 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20210517:cpp-random" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Various.              “¡random¿”.              In:              <span class="rm-lmri-10" style="font-style: italic;">cplusplus.com             </span>(2021).              <span class="small-caps" style="font-variant: small-caps;">url</span>:
<a href="https://www.cplusplus.com/reference/random/" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.cplusplus.com/reference/random/</span></a>.
</p>    
</dd>
<dt id="X0-20210517:java" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[7]  
</dt><dd id="bib-7" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 45 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20210517:java" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Various.       “Class       Random”.       In:       <span class="rm-lmri-10" style="font-style: italic;">Java      8      Documentation       </span>(2021).       <span class="small-caps" style="font-variant: small-caps;">url</span>:
<a href="https://docs.oracle.com/javase/8/docs/api/java/util/Random.html" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://docs.oracle.com/javase/8/docs/api/java/util/Random.html</span></a>.
</p>    
</dd>
<dt id="X0-20210517:cpp-rand" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[8]  
</dt><dd id="bib-8" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 45 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20210517:cpp-rand" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Various.                “rand”.                In:                <span class="rm-lmri-10" style="font-style: italic;">cplusplus.com               </span>(2021).                <span class="small-caps" style="font-variant: small-caps;">url</span>:
<a href="https://www.cplusplus.com/reference/cstdlib/rand/" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.cplusplus.com/reference/cstdlib/rand/</span></a>.</p></dd></dl>

 

]]></description>
	</item>
	<item>
		<title>Homoglyphs аnd Homogrаphic Аttаcks</title>
		<link>https://www.SwATips.com/articles/20210510.html</link>
		<pubDate>Mon, 10 May 2021 00:00:00 -0500</pubDate>
<description><![CDATA[

<p style="margin-top: 0; margin-bottom: 0;">Return to <a href="/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">SwATips</a> | <a href="articles/20210510.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">pdf</a> | <a rel="license" href="http://creativecommons.org/licenses/by/4.0/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/by.svg" width="60" height="21" alt="CC-BY" style="border-top: 0; border-left: 0; border-right: 0;"/></a></p>


<div class="maketitle" style="margin-top: 1em; text-align: center; margin-bottom: 2em;">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead" style="text-align: center;"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a href="#cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1</a>]<br/>
Generated Friday 7<sup class="textsuperscript">th</sup> May, 2021</h2>
<div class="author" style="text-align: center;"><span class="rm-lmr-12" style="font-size: 120%;">Jon Hood</span></div><br/>
<div class="date" style="text-align: center;"><span class="rm-lmr-12" style="font-size: 120%;">Monday 10</span><sup class="textsuperscript"><span class="rm-lmr-9" style="font-size: 90%;">th</span></sup><span class="rm-lmr-12" style="font-size: 120%;"> May, 2021</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead"><span class="titlemark">1   </span> <a id="x1-10001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Homoglyphs аnd Homogrаphic Аttаcks</h3>


<!-- l. 1 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Do you hаve аn OS X system аnd would like to get our totаlly trustworthy, Аpple-certified softwаre on your
mаchine? Then be sure to run the commаnd in Listing <a href="#x1-1001r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1<!-- tex4ht:ref: lst:20210510:1  --></a>!
</p>
   

<!-- l. 3 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-1001r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-1002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>
   

<div class="lstlisting" id="listing-1" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-1003r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">sh-3.2</span><span class="ec-lmtti-10x-x-90" style="font-size: 90%; font-family: monospace,monospace; font-style: italic;"># softwareupdate --set-catalog http://</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">оѕх</span><span class="ec-lmtti-10x-x-90" style="font-size: 90%; font-family: monospace,monospace; font-style: italic;">.com</span>
<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 1:</span><span class="content">Totаlly Legit-Looking OSX Updаte Site</span></figcaption><!-- tex4ht:label?: x1-1001r1  -->
   
</div>


<!-- l. 14 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   If you were to copy+pаste thаt аddress in your browser, you’d be tаken bаck to our Softwаre Аssurаnce Tips
pаge. It’s not the reаl OSX.com! Аttаckers often use <i>homoglyphs</i>–chаrаcters thаt look identicаl to the end user but
аre аctuаlly а different chаrаcter set. Our eyes mаy think thаt “оѕх.com” аnd “osx.com” look identicаl (аnd
pixel-for-pixel, they аre identicаl). However, the first one uses Cyrillic chаrаcters, meаning thаt they аre two
different аddresses!
</p>
<!-- l. 16 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.1   </span> <a id="x1-20001.1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Аttаcks</h4>


<!-- l. 18 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">In the pаst, аttаckers used а technique known аs “soundsquаtting” to reserve homophonous domаins to trick
unsuspecting users. Аn аttаcker would register а homophone (eg: “whether” vs. “weаther”) аnd set up а mirrored
аttаck site to gleen credentiаls from their victims.[<a href="#cite.0@20210510:nikiforakis2014soundsquatting" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2</a>]
</p>
<!-- l. 20 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Suppose thаt а system mаkes sure thаt only trusted friends cаn request а “Call for Fire” to аn enemy locаtion.
Whаt would hаppen if аn enemy were аble to send the unfiltered “Cаll for Fire” where the “a” chаrаcter hаs been
replаced with the Cyrillic chаrаcter “а”?
</p>
<!-- l. 22 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.2   </span> <a id="x1-30001.2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Conclusion</h4>


<!-- l. 24 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Mаybe you think you’re too good аnd wouldn’t hаve been fooled by the fаke OSX аddress аt the beginning of this
аrticle. But I bet you were fooled with the fаct thаt neаrly every letter “a” hаs been replаced with the Cyrillic
chаrаcter “а” throughout this аrticle. Аnd you didn’t even notice!
                                                                                         
                                                                                         
</p>
   

<h3 class="sectionHead"><a id="x1-40001.2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>References</h3>


<!-- l. 45 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">    
</p>


<dl class="thebibliography"><dt class="thebibliography" id="X0-swatips" style="float: left; clear: left; margin-right: 1em;">
[1]  
</dt><dd class="thebibliography" id="bib-1" style="margin-left: 2.5em;">
<!-- l. 45 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon Hood, ed. <span class="rm-lmri-10" style="font-style: italic;">SwATips</span>. <a href="https://www.SwATips.com/" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.SwATips.com/</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-20210510:nikiforakis2014soundsquatting" style="float: left; clear: left; margin-right: 1em;">
[2]  
</dt><dd class="thebibliography" id="bib-2" style="margin-left: 2.5em;">
<!-- l. 45 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20210510:nikiforakis2014soundsquatting" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Nick Nikiforakis et al. “Soundsquatting: Uncovering the use of homophones in domain squatting”. In:
<span class="rm-lmri-10" style="font-style: italic;">International Conference on Information Security</span>. Springer. 2014, pp. 291–308.</p></dd></dl>

 

]]></description>
	</item>
	<item>
		<title>Downloading Package Dependencies for Offline Installs in Debian-based Distributions</title>
		<link>https://www.SwATips.com/articles/20210503.html</link>
		<pubDate>Mon, 03 May 2021 00:00:00 -0500</pubDate>
<description><![CDATA[

<p style="margin-top: 0; margin-bottom: 0;">Return to <a href="/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">SwATips</a> | <a href="articles/20210503.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">pdf</a> | <a rel="license" href="http://creativecommons.org/licenses/by/4.0/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/by.svg" width="60" height="21" alt="CC-BY" style="border-top: 0; border-left: 0; border-right: 0;"/></a></p>


<div class="maketitle" style="margin-top: 1em; text-align: center; margin-bottom: 2em;">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead" style="text-align: center;"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a href="#cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1</a>]<br/>
Generated Friday 7<sup class="textsuperscript">th</sup> May, 2021</h2>
 <div class="author" style="text-align: center;"><span class="rm-lmr-12" style="font-size: 120%;">Kevin Keen</span></div><br/>
<div class="date" style="text-align: center;"><span class="rm-lmr-12" style="font-size: 120%;">Monday 3</span><sup class="textsuperscript"><span class="rm-lmr-9" style="font-size: 90%;">rd</span></sup><span class="rm-lmr-12" style="font-size: 120%;"> May, 2021</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead"><span class="titlemark">1   </span> <a id="x1-10001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Downloading Package Dependencies for Offline Installs in Debian-based Distributions</h3>


<!-- l. 1 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Sometimes in Software Assurance there exists the need to keep a machine from ever again connecting to a network.
Perhaps a customer doesn’t wish even the most remote risk that their code could be visible on a network. Or
perhaps the analyst is examining malware. Or perhaps the results of a vulnerability scan need to be protected at a
level higher than the network that is available. Reasons abound for keeping a machine offline, but when we need to
install new software on these machines, it can be a harrowing experience. Those that have tried to install new
packages offline in Debian-based environments are familiar with the “dependency hell” that quickly ensues. It is easy
to overlook how much work a simple command like <span class="ec-lmtt-10" style="font-family: monospace,monospace;">apt-get </span>does until one tries to reproduce that effort
manually.
</p>
<!-- l. 3 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   One solution is to find one of various repository websites that list the package’s dependencies and one by one
visit each page to manually download them. While this can work, it is time-consuming and error-prone. A better
solution is to let a utility like <span class="ec-lmtt-10" style="font-family: monospace,monospace;">apt </span>do the heavy lifting of identifying and downloading the dependencies in an
automated manner.
</p>
<!-- l. 5 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Recently we had a similar situation. Although we had tried to find solutions in the past, most required scripts or
third-party software. This time, however, we were able to find the command in Listing <a href="#x1-1001r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1<!-- tex4ht:ref: lst:20210503:so  --></a> on Stack
Overflow.[<a href="#cite.0@20210503-stackoverflow" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2</a>]
</p>
   

<!-- l. 7 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-1001r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-1002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>
   

<div class="lstlisting" id="listing-1" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-1003r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">apt-get download \\ </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1004r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        $(apt-cache depends \\ </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1005r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">               --recurse --no-recommends --no-suggests \\ </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1006r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">               --no-conflicts --no-breaks --no-replaces \\ </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1007r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">               --no-enhances &lt;your-package-here&gt; \\ </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1008r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">               | grep "^\w" | sort -u)</span>
<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 1:</span><span class="content">Deep Dependency Downloading</span></figcaption><!-- tex4ht:label?: x1-1001r1  -->
   
</div>


<!-- l. 16 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Breaking down the command, the portion inside the <span class="ec-lmtt-10" style="font-family: monospace,monospace;">$() </span>is executed first which searches the apt cache for
dependencies of the selected package. The --no…options are generally needed to prevent optional or breaking
packages from being included. Note that in some cases, these may need to be tweaked. For example, if there were a
need to upgrade a package that is already installed on the offline machine, one may wish to remove the
<span class="ec-lmtt-10" style="font-family: monospace,monospace;">--no-replaces </span>flag. Next, this output is passed to <span class="ec-lmtt-10" style="font-family: monospace,monospace;">grep </span>to filter out some lines of output that are not needed.
Then, the output gets piped to <span class="ec-lmtt-10" style="font-family: monospace,monospace;">sort </span>with the <span class="ec-lmtt-10" style="font-family: monospace,monospace;">-u </span>flag in order to remove duplicates. Finally, <span class="ec-lmtt-10" style="font-family: monospace,monospace;">apt-get download </span>is
called on each resulting line.  </p>
<div class="awesomebox" id="awesomebox-1" style="display: grid; grid-template-columns: 90px auto; margin-top: 1rem; margin-bottom: 1rem;"><div class="icon" style="padding-right: 0.5rem; margin-right: 0.5rem; text-align: center; border-right: 4px solid #19407A;"><img alt=" " src="data:image/svg+xml;base64,PD94bWwgdmVyc2lvbj0nMS4wJyBlbmNvZGluZz0nVVRGLTgnPz4KPCEtLSBUaGlzIGZpbGUgd2FzIGdlbmVyYXRlZCBieSBkdmlzdmdtIDIuMTEuMSAtLT4KPHN2ZyB2ZXJzaW9uPScxLjEnIHhtbG5zPSdodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZycgeG1sbnM6eGxpbms9J2h0dHA6Ly93d3cudzMub3JnLzE5OTkveGxpbmsnIHdpZHRoPSczNC4xNDY2NDVwdCcgaGVpZ2h0PSczMy41OTE0MTVwdCcgdmlld0JveD0nMzYuODA2MzUyIDUzMy4xMTE5NDIgMzQuMTQ2NjQ1IDMzLjU5MTQxNSc+CjxkZWZzPgo8cGF0aCBpZD0nZzItMjQwJyBkPSdNMTIuMzkzNTI3LTIxLjI5MjA3OUM1Ljc3NTM4My0yMS4yOTIwNzkgLjM5NjU5My0xNS45MTMyODggLjM5NjU5My05LjI5NTE0NUMuMzk2NTkzLTIuNjUyMjE1IDUuNzc1MzgzIDIuNzAxNzg5IDEyLjM5MzUyNyAyLjcwMTc4OVMyNC4zOTA0NjEtMi42NTIyMTUgMjQuMzkwNDYxLTkuMjk1MTQ1QzI0LjM5MDQ2MS0xNS45MTMyODggMTkuMDExNjctMjEuMjkyMDc5IDEyLjM5MzUyNy0yMS4yOTIwNzlaTTEyLjM5MzUyNy0xNS45ODc2NDlDMTMuNTA4OTQ0LTE1Ljk4NzY0OSAxNC40MjYwNjUtMTUuMDQ1NzQxIDE0LjQyNjA2NS0xMy45MzAzMjRTMTMuNTA4OTQ0LTExLjg5Nzc4NiAxMi4zOTM1MjctMTEuODk3Nzg2UzEwLjM2MDk4OC0xMi44MTQ5MDcgMTAuMzYwOTg4LTEzLjkzMDMyNFMxMS4yNzgxMDktMTUuOTg3NjQ5IDEyLjM5MzUyNy0xNS45ODc2NDlaTTE1LjA5NTMxNi0zLjY2ODQ4NEMxNS4wOTUzMTYtMy4zNDYyNTIgMTQuODQ3NDQ1LTMuMDk4MzgyIDE0LjUyNTIxMy0zLjA5ODM4MkgxMC4yNjE4NEM5LjkzOTYwOC0zLjA5ODM4MiA5LjY5MTczOC0zLjM0NjI1MiA5LjY5MTczOC0zLjY2ODQ4NFYtNC44MzM0NzVDOS42OTE3MzgtNS4xNTU3MDcgOS45Mzk2MDgtNS40MjgzNjUgMTAuMjYxODQtNS40MjgzNjVIMTAuODU2NzI5Vi04LjUyNjc0NkgxMC4yNjE4NEM5LjkzOTYwOC04LjUyNjc0NiA5LjY5MTczOC04Ljc3NDYxNyA5LjY5MTczOC05LjA5Njg0OVYtMTAuMjYxODRDOS42OTE3MzgtMTAuNTg0MDcyIDkuOTM5NjA4LTEwLjg1NjcyOSAxMC4yNjE4NC0xMC44NTY3MjlIMTMuMzYwMjIyQzEzLjY4MjQ1My0xMC44NTY3MjkgMTMuOTMwMzI0LTEwLjU4NDA3MiAxMy45MzAzMjQtMTAuMjYxODRWLTUuNDI4MzY1SDE0LjUyNTIxM0MxNC44NDc0NDUtNS40MjgzNjUgMTUuMDk1MzE2LTUuMTU1NzA3IDE1LjA5NTMxNi00LjgzMzQ3NVYtMy42Njg0ODRaJy8+CjwvZGVmcz4KPGcgaWQ9J3BhZ2UxJyB0cmFuc2Zvcm09J21hdHJpeCgxLjQgMCAwIDEuNCAwIDApJz4KPGcgZmlsbD0nIzE5NDA3YSc+Cjx1c2UgeD0nMjYuMjkwMjUxJyB5PSc0MDIuMDg2MzIzJyB4bGluazpocmVmPScjZzItMjQwJy8+CjwvZz4KPC9nPgo8L3N2Zz4="/></div><div class="boxcontent" style="vertical-align: top;">
<!-- l. 17 --><p class="indent" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   Be sure that the online machine is the same OS version as the offline machine. Otherwise, the packages
downloaded might not be compatible with the offline machine. Potentially with dire consequences!
</p></div></div>


<!-- l. 19 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   This can quickly and easily allow a package and its dependencies to be downloaded for transfer to the offline
machine.
                                                                                         
                                                                                         
</p>
   

<h3 class="sectionHead"><a id="x1-20001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>References</h3>


<!-- l. 45 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">    
</p>


<dl class="thebibliography"><dt class="thebibliography" id="X0-swatips" style="float: left; clear: left; margin-right: 1em;">
[1]  
</dt><dd class="thebibliography" id="bib-1" style="margin-left: 2.5em;">
<!-- l. 45 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon Hood, ed. <span class="rm-lmri-10" style="font-style: italic;">SwATips</span>. <a href="https://www.SwATips.com/" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.SwATips.com/</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-20210503-stackoverflow" style="float: left; clear: left; margin-right: 1em;">
[2]  
</dt><dd class="thebibliography" id="bib-2" style="margin-left: 2.5em;">
<!-- l. 45 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20210503-stackoverflow" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Yann Vo. “How to list/download the recursive dependencies of a debian package?” In: (2019). <span class="small-caps" style="font-variant: small-caps;">url</span>:
<a href="https://stackoverflow.com/a/41428445" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://stackoverflow.com/a/41428445</span></a>.</p></dd></dl>

 

]]></description>
	</item>
	<item>
		<title>Polymorphic Catch Performance in C#</title>
		<link>https://www.SwATips.com/articles/20210426.html</link>
		<pubDate>Mon, 26 Apr 2021 00:00:00 -0500</pubDate>
<description><![CDATA[

<p style="margin-top: 0; margin-bottom: 0;">Return to <a href="/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">SwATips</a> | <a href="articles/20210426.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">pdf</a> | <a rel="license" href="http://creativecommons.org/licenses/by/4.0/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/by.svg" width="60" height="21" alt="CC-BY" style="border-top: 0; border-left: 0; border-right: 0;"/></a></p>


<div class="maketitle" style="margin-top: 1em; text-align: center; margin-bottom: 2em;">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead" style="text-align: center;"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a href="#cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1</a>]<br/>
Generated Friday 7<sup class="textsuperscript">th</sup> May, 2021</h2>
<div class="author" style="text-align: center;"><span class="rm-lmr-12" style="font-size: 120%;">Jon Hood</span></div><br/>
<div class="date" style="text-align: center;"><span class="rm-lmr-12" style="font-size: 120%;">Monday 26</span><sup class="textsuperscript"><span class="rm-lmr-9" style="font-size: 90%;">th</span></sup><span class="rm-lmr-12" style="font-size: 120%;"> April, 2021</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead"><span class="titlemark">1   </span> <a id="x1-10001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Polymorphic Catch Performance in C#</h3>


<!-- l. 1 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">In a recent code review, one of our customers were marked for being sloppy with catch-all exceptions (CWE-396),
which is sometimes an indicator of poorly designed program flow. To fix this, the developers changed the catch
blocks to something like the one in Listing <a href="#x1-1001r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1<!-- tex4ht:ref: lst:20210426:exception  --></a>.
</p>
   

<!-- l. 3 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-1001r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-1002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>
   

<div class="lstlisting" id="listing-1" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-1003r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>1</span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">try</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1004r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>2</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">{ DoSomethingWith("C:\\File.txt"); } </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1005r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>3</span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">catch</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> (Exception e) when (e </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">is</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> FileNotFoundException) </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1006r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>4</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">{ DoSomethingElse(e); }</span>
<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 1:</span><span class="content">When-Conditioned Exception</span></figcaption><!-- tex4ht:label?: x1-1001r1  -->
   
</div>


<!-- l. 10 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   The intent of a “when” clause in an exception is for situations where the exception may have an error
code. For example, a SqlException may return different codes that can be used to differentiate their
catch blocks and clean up a failed state. So how does the code in Listing <a href="#x1-1001r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1<!-- tex4ht:ref: lst:20210426:exception  --></a> differ from the code in
Listing <a href="#x1-1007r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2<!-- tex4ht:ref: lst:20210426:exception2  --></a>?
</p>
   

<!-- l. 12 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-1007r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-1008" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>
   

<div class="lstlisting" id="listing-2" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-1009r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>1</span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">try</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1010r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>2</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">{ DoSomethingWith("C:\\File.txt"); } </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1011r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>3</span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">catch</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> (FileNotFoundException e) </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1012r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>4</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">{ DoSomethingElse(e); }</span>
<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 2:</span><span class="content">Classically-Conditioned Exception</span></figcaption><!-- tex4ht:label?: x1-1007r1  -->
   
</div>


<!-- l. 19 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   While both blocks of code achieve the same result, the generated code to catch the exception in Listing <a href="#x1-1001r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1<!-- tex4ht:ref: lst:20210426:exception  --></a> has
twelve times as many instructions to execute. The .NET Intermediate Language (IL) is very different between the
two implementations. The “when” clause creates what the IL defines as a filter block and instantiates a structure
similar to a truth stack. This additional structure and the extra operations on it reduce performance and add
unnecessary bloat to the software. The generated IL can be compared in Listings <a href="#x1-1013r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">3<!-- tex4ht:ref: lst:20210426:exceptionil  --></a> and <a href="#x1-1029r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">4<!-- tex4ht:ref: lst:20210426:exception2il  --></a>. The IL was created in
optimized Release mode.
</p>
   

<!-- l. 21 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-1013r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-1014" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>
   

<div class="lstlisting" id="listing-3" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-1015r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>1</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">filter { </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1016r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>2</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">IL_000d:  isinst [System.Runtime]System.Exception </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1017r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>3</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">IL_0012:  dup </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1018r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>4</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">IL_0013:  brtrue.s IL_0019 </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1019r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>5</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">IL_0015:  pop </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1020r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>6</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">IL_0016:  ldc.i4.0 </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1021r7" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>7</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">IL_0017:  br.s IL_0024 </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1022r8" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>8</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">IL_0019:  isinst [System.Runtime]System.IO.FileNotFoundException </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1023r9" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>9</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">IL_001e:  ldnull </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1024r10" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>10</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">IL_001f:  cgt.un </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1025r11" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>11</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">IL_0021:  ldc.i4.0 </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1026r12" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>12</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">IL_0022:  cgt.un </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1027r13" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>13</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">IL_0024:  endfilter </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1028r14" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>14</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">}</span>
<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 3:</span><span class="content">When-Conditioned Exception IL</span></figcaption><!-- tex4ht:label?: x1-1013r1  -->
   
</div>


<!-- l. 38 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-1029r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-1030" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>
   

<div class="lstlisting" id="listing-4" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-1031r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>1</span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">catch</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">class</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> [mscorlib]System.IO.FileNotFoundException</span>
<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 4:</span><span class="content">Classically-Conditioned Exception IL</span></figcaption><!-- tex4ht:label?: x1-1029r1  -->
   
</div>


<!-- l. 42 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   This leads to another question: what’s the most optimal way to catch several types of exceptions? The most
optimal way is to catch the general exception, then use polymorphism to operate on it (code in Listing <a href="#x1-1032r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">5<!-- tex4ht:ref: lst:20210426:exceptionif  --></a>). The IL
code adds a single comparison for each conditional in an if statement and avoids the overhead incurred by the when
clause’s filter block. Note that most scanning tools and style checkers will identify Listing <a href="#x1-1032r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">5<!-- tex4ht:ref: lst:20210426:exceptionif  --></a> as a catch
                                                                                         
                                                                                         
for the generic exception, but this should be marked as a false positive if the handler appropriately
determines the failure scenarios for the appropriate exception types. The IL code for Listing <a href="#x1-1032r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">5<!-- tex4ht:ref: lst:20210426:exceptionif  --></a> up to the
first exception type is shown in Listing <a href="#x1-1043r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">6<!-- tex4ht:ref: lst:20210426:exceptionifil  --></a>. Please also realize that such minimal performance gains
should not be interpreted as a reason to violate a consistent standard already established in a code
base.
</p>
   

<!-- l. 44 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-1032r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-1033" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>
   

<div class="lstlisting" id="listing-5" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-1034r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>1</span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">try</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1035r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>2</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">{ DoSomethingWith("C:\\File.txt"); } </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1036r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>3</span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">catch</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> (Exception e) </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1037r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>4</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">{ </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1038r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>5</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">       </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">if</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> ((e </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">is</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> FileNotFoundException) || (e </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">is</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> SecurityException)) </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1039r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>6</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">               DoSomethingElse(e); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1040r7" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>7</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">       </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">else</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1041r8" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>8</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">               Log(e); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1042r9" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>9</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">}</span>
<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 5:</span><span class="content">If-Formatted Exception Chain</span></figcaption><!-- tex4ht:label?: x1-1032r1  -->
   
</div>


<!-- l. 56 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-1043r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-1044" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>
   

<div class="lstlisting" id="listing-6" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-1045r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>1</span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">catch</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">class</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> [mscorlib]System.Exception { </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1046r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>2</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">       IL_000d:  isinst [System.Runtime]System.IO.FileNotFoundException</span>
<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 6:</span><span class="content">If-Formatted Exception Chain IL</span></figcaption><!-- tex4ht:label?: x1-1043r1  -->
   
</div>


<!-- l. 61 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   When performance is a primary concern, developers should include comments that indicate their consideration of
exceptional cases in generic catch blocks. Validators should watch for these comments to help them mark the generic
exception catches as false positives.
                                                                                         
                                                                                         
</p>
   

<h3 class="sectionHead"><a id="x1-20001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>References</h3>


<!-- l. 45 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">    
</p>


<dl class="thebibliography"><dt id="X0-swatips" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[1]  
</dt><dd id="bib-1" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 45 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon Hood, ed. <span class="rm-lmri-10" style="font-style: italic;">SwATips</span>. <a class="url" href="https://www.SwATips.com/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.SwATips.com/</span></a>.</p></dd></dl>

 

]]></description>
	</item>
	<item>
		<title>Heap Inspection</title>
		<link>https://www.SwATips.com/articles/20210419.html</link>
		<pubDate>Mon, 19 Apr 2021 00:00:00 -0500</pubDate>
<description><![CDATA[

<p style="margin-top: 0; margin-bottom: 0;">Return to <a href="/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">SwATips</a> | <a href="articles/20210419.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">pdf</a> | <a rel="license" href="http://creativecommons.org/licenses/by/4.0/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/by.svg" width="60" height="21" alt="CC-BY" style="border-top: 0; border-left: 0; border-right: 0;"/></a></p>


<div class="maketitle" style="margin-top: 1em; text-align: center; margin-bottom: 2em;">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead" style="text-align: center;"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a href="#cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2</a>]<br/>
Generated Friday 7<sup class="textsuperscript">th</sup> May, 2021</h2>
<div class="author" style="text-align: center;"><span class="rm-lmr-12" style="font-size: 120%;">Andrew Perry</span></div><br/>
<div class="date" style="text-align: center;"><span class="rm-lmr-12" style="font-size: 120%;">Monday 19</span><sup class="textsuperscript"><span class="rm-lmr-9" style="font-size: 90%;">th</span></sup><span class="rm-lmr-12" style="font-size: 120%;"> April, 2021</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead"><span class="titlemark">1   </span> <a id="x1-10001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Heap Inspection</h3>


<!-- l. 1 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">One of the first findings that I found when I began validating software assurance scans and something that intrigued
me to learn more about was <i>Heap Inspections</i>.[<a href="#cite.0@20210419-cwe-244" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1</a>] In order to know how to resolve this issue, there are some things to
understand about how heap is used in RAM in order to see how this vulnerability plays out and ways to fix
it.
</p>
<!-- l. 3 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.1   </span> <a id="x1-20001.1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>What is Heap?</h4>


<!-- l. 5 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">When we declare a variable in an application, it allocates some memory in RAM. A stack is an array of memory
that stores variables and implements a block allocation that is reserved in a LIFO (Last in, First out). When data
are written, the stack trends downwards towards the heap. The heap is a location in memory that a program can
use to store data in some various amount that may not be known until the program is running. Heap trends
upwards when data is passed whereas a stack trends in a downward direction. When creating an object string that
points to the stack memory, its value is stored in the heap. Heap is different than stack in that it is dynamically
stored in memory which means that it can be stored and removed in any order. If the heap has data that has
a fixed length memory block, it will overwrite expired or free values that were originally stored.[<a href="#cite.0@20210419-guru99" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">5</a>,
<a href="#cite.0@20210419-indika" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">3</a>]
</p>
<!-- l. 7 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.2   </span> <a id="x1-30001.2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>What is Heap Inspection?</h4>


<!-- l. 9 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">In the case of a Heap Inspection, when information is stored in machine memory that is unencrypted and is using a
<span class="ec-lmtt-10" style="font-family: monospace,monospace;">realloc() </span>function to increase the size of the block of allocated memory, an attacker can perform a memory dump
that could compromise the system. This can cause all kinds of problems such as crash the program, but it can also
expose sensitive information because it is not removed from memory properly. There are some ways to help mitigate
this issue in C# or .NET applications.
</p>
<!-- l. 11 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.3   </span> <a id="x1-40001.3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Heap Inspection Prevention</h4>


<!-- l. 13 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Using the <span class="ec-lmtt-10" style="font-family: monospace,monospace;">String </span>object should not be used if the information contains sensitive information such as a password,
credit card number, etc. It is important to not allow plain text passwords; hash them with a crytographically secure
hasing algorithm. An important note is to invoke a Disposable method to use as a garbage collector to
free computer memory when an object is no longer needed. One of the ways you can avoid a heap
inspection and to protect sensitive data is by using a <span class="ec-lmtt-10" style="font-family: monospace,monospace;">SecureString</span>. Consider the code in Listing <a href="#x1-4001r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1<!-- tex4ht:ref: fig:20210419:1  --></a>.[<a href="#cite.0@20210419-codeproject" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">6</a>,
<a href="#cite.0@20210419-swain" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">4</a>]
</p>
   

<!-- l. 15 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-4001r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-4002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>
   

<div id="listing-1" class="lstlisting" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-4003r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">SecureString securePwd = </span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">new</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> SecureString(); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-4004r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">ConsoleKeyInfo key; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-4005r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">Console.Write("Enter password: "); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-4006r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">do</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> { </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-4007r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        key = Console.ReadKey(</span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">true</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">);…</span>
<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 1:</span><span class="content">SecureString Example</span></figcaption><!-- tex4ht:label?: x1-4001r1  -->
   
</div>

                                                                                         
                                                                                         

<!-- l. 24 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.4   </span> <a id="x1-50001.4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Conclusion</h4>


<!-- l. 26 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">In conclusion, avoiding this issue can be a challenge, if not impossible. However, it’s important that if this finding
has been found in a static analysis scan, it should not be marked as a false positive, particularly if the code
could ever be placed in a shared environment. Doing so may allow the code to go unnoticed while
it continues to have unintended results and could allow sensitive information to be obtained by an
adversary.
                                                                                         
                                                                                         
</p>
   

<h3 class="sectionHead"><a id="x1-60001.4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>References</h3>


<!-- l. 45 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">    
</p>


<dl class="thebibliography"><dt id="X0-20210419-cwe-244" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[1]  
</dt><dd id="bib-1" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 45 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20210419-cwe-244" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>CWE  Content  Team.  “CWE-244:  Improper  Clearing  of  Heap  Memory  Before  Release  (’Heap
Inspection’)”. In: (2020). <span class="small-caps" style="font-variant: small-caps;">url</span>: <a class="url" href="https://cwe.mitre.org/data/definitions/244.html" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://cwe.mitre.org/data/definitions/244.html</span></a>.
</p>    
</dd>
<dt id="X0-swatips" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[2]  
</dt><dd id="bib-2" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 45 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon Hood, ed. <span class="rm-lmri-10" style="font-style: italic;">SwATips</span>. <a class="url" href="https://www.SwATips.com/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.SwATips.com/</span></a>.
</p>    
</dd>
<dt id="X0-20210419-indika" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[3]  
</dt><dd id="bib-3" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 45 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20210419-indika" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Indika.        “Difference        Between        Stack        and        Heap”.        In:        (2011).        <span class="small-caps" style="font-variant: small-caps;">url</span>:
<a class="url" href="https://www.differencebetween.com/difference-between-stack-and-vs-heap/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.differencebetween.com/difference-between-stack-and-vs-heap/</span></a>.
</p>    
</dd>
<dt id="X0-20210419-swain" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[4]  
</dt><dd id="bib-4" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 45 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20210419-swain" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Chittaranjan Swain. “How to fix heap inspection vulnerability in c#”. In: (2019). <span class="small-caps" style="font-variant: small-caps;">url</span>: <a class="url" href="https://www.c-sharpcorner.com/forums/how-to-fix-heap-inspection-vulnerability-in-c-sharp" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.c-sharpcorner.com/forums/how-to-fix-heap-inspection-vulnerability-in-c-sharp</span></a>.
</p>    
</dd>
<dt id="X0-20210419-guru99" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[5]  
</dt><dd id="bib-5" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 45 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20210419-guru99" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Unknown.       “Stack       vs       Heap:       Know       the       Difference”.       In:       ().       <span class="small-caps" style="font-variant: small-caps;">url</span>:
<a class="url" href="https://www.guru99.com/stack-vs-heap.html" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.guru99.com/stack-vs-heap.html</span></a>.
</p>    
</dd>
<dt id="X0-20210419-codeproject" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[6]  
</dt><dd id="bib-6" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 45 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20210419-codeproject" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Unknown. “To Avoid Heap Inspection”. In: (2015). <span class="small-caps" style="font-variant: small-caps;">url</span>: <a class="url" href="https://www.codeproject.com/Questions/1039781/To-Avoid-Heap-Inspection-I-Used-Securestring-Inste" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.codeproject.com/Questions/1039781/To-Avoid-Heap-Inspection-I-Used-Securestring-Inste</span></a>.</p></dd></dl>

 

]]></description>
	</item>
	<item>
		<title>Sticking with a RAII Standard</title>
		<link>https://www.SwATips.com/articles/20210412.html</link>
		<pubDate>Mon, 12 Apr 2021 00:00:00 -0500</pubDate>
<description><![CDATA[

<p style="margin-top: 0; margin-bottom: 0;">Return to <a href="/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">SwATips</a> | <a href="articles/20210412.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">pdf</a> | <a rel="license" href="http://creativecommons.org/licenses/by/4.0/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/by.svg" width="60" height="21" alt="CC-BY" style="border-top: 0; border-left: 0; border-right: 0;"/></a></p>


<div class="maketitle" style="margin-top: 1em; text-align: center; margin-bottom: 2em;">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead" style="text-align: center;"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a href="#cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1</a>]<br/>
Generated Friday 7<sup class="textsuperscript">th</sup> May, 2021</h2>
<div class="author" style="text-align: center;"><span class="rm-lmr-12" style="font-size: 120%;">Jon Hood</span></div><br/>
<div class="date" style="text-align: center;"><span class="rm-lmr-12" style="font-size: 120%;">Monday 12</span><sup class="textsuperscript"><span class="rm-lmr-9" style="font-size: 90%;">th</span></sup><span class="rm-lmr-12" style="font-size: 120%;"> April, 2021</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead"><span class="titlemark">1   </span> <a id="x1-10001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Sticking with a RAII Standard</h3>


<!-- l. 1 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Resource Acquisition Is Initialization (RAII). When working with legacy code, often variables and memory
management do not use RAII concepts. When memory is created in an uninitialized state, developers risk the use of
uninitialized memory further down in the application data flow.
</p>
<!-- l. 3 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   To solve this, C++ implemented two ways of initializing new memory: <i>default</i> initialization and <i>value</i>
initialization. While default initialization is typically faster, developers quickly realized that there was rarely a
reason to keep memory uninitialized. Initializing memory as soon as it’s allocated keeps developers from shooting
themselves in the foot.
</p>
<!-- l. 5 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   One of the best ways to prevent memory errors is to use RAII. Particularly in exception-based code, RAII
concepts provide a memory-safe technique for resource management.[<a href="#cite.0@20210412-stroustrup2001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2</a>] Several issues face developers when
maintaining legacy code with new programming concepts, particularly in the DoD. Legacy code is
generally void of RAII concepts and has not been built with the latest standards of safe programming
practices.
</p>
<!-- l. 7 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.1   </span> <a id="x1-20001.1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Updating the Code</h4>


<!-- l. 9 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">The first option for maintaining legacy code in a memory-safe way is to update the code. Wrapping old pointers in
smart pointers can help make the code more maintainable.
</p>
   

<!-- l. 11 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-2001r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-2002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>
   

<div id="listing-1" class="lstlisting" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-2003r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">bool *newBool = new bool(); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-2004r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">if</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> (*newBool) </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-2005r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        cout &lt;&lt; "We</span><span class="ts1-lmtt9-" style="font-size: 90%;">'</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">re␣true!"␣&lt;&lt;␣endl; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-2006r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">else </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-2007r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">␣␣␣␣␣␣␣␣cout␣&lt;&lt;␣"We</span><span class="ts1-lmtt9-" style="font-size: 90%;">'</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">re false!" &lt;&lt; endl; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-2008r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">delete newBool;</span>
<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 1:</span><span class="content">Non-compliant listing</span></figcaption><!-- tex4ht:label?: x1-2001r1  -->
   
</div>


<!-- l. 20 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-2009r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-2010" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>
   

<div id="listing-2" class="lstlisting" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-2011r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">auto</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> newBool = make_shared&lt;bool&gt;(); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-2012r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtti-10x-x-90" style="font-size: 90%; font-family: monospace,monospace; font-style: italic;">//Another way: shared_ptr&lt;bool&gt; newBool(new bool());</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-2013r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">if</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> (*newBool) </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-2014r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        cout &lt;&lt; "We</span><span class="ts1-lmtt9-" style="font-size: 90%;">'</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">re␣true!"␣&lt;&lt;␣endl; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-2015r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">else </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-2016r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">␣␣␣␣␣␣␣␣cout␣&lt;&lt;␣"We</span><span class="ts1-lmtt9-" style="font-size: 90%;">'</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">re false!" &lt;&lt; endl;</span>
<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 2:</span><span class="content">RAII-compliant listing</span></figcaption><!-- tex4ht:label?: x1-2009r1  -->
   
</div>


<!-- l. 29 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   There are several issues with updating the old code to the RAII-compliant code:
</p>
     

<ol class="enumerate1" style="list-style-type: decimal;">
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
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.2   </span> <a id="x1-30001.2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Double Frees</h4>


<!-- l. 39 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Developers can introduce double free conditions where a pointer is managed by both a smart pointer and in the
code itself. Also, conditions arise when a single pointer is handed over to multiple smart pointers for
management.
</p>
<!-- l. 41 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   At the time of this writing, the latest versions of Fortify, Coverity, Checkmarx, Parasoft, clang-analyzer,
and the GCC 10 <span class="ec-lmtt-10" style="font-family: monospace,monospace;">-fanalyzer </span>flag are all incapable of identifying the double free in Listings <a href="#x1-3001r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">3<!-- tex4ht:ref: lst:20210412:1  --></a> and
<a href="#x1-3007r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">4<!-- tex4ht:ref: lst:20210412:2  --></a>.
</p>
   

<!-- l. 43 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-3001r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-3002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>
   

<div id="listing-3" class="lstlisting" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-3003r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">bool *newBool = new bool(); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-3004r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">shared_ptr&lt;bool&gt; test1 (newBool); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-3005r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">shared_ptr&lt;bool&gt; test2 (newBool); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-3006r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtti-10x-x-90" style="font-size: 90%; font-family: monospace,monospace; font-style: italic;">//...</span>
<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 3:</span><span class="content">Double Smart Pointer</span></figcaption><!-- tex4ht:label?: x1-3001r1  -->
   
</div>


<!-- l. 50 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-3007r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-3008" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>
   

<div id="listing-4" class="lstlisting" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-3009r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">bool *newBool = new bool(); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-3010r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">shared_ptr&lt;bool&gt; test1 (newBool); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-3011r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtti-10x-x-90" style="font-size: 90%; font-family: monospace,monospace; font-style: italic;">//...</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-3012r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">delete newBool;</span>
<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 4:</span><span class="content">Smart and Dumb Pointer</span></figcaption><!-- tex4ht:label?: x1-3007r1  -->
   
</div>


<!-- l. 57 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.3   </span> <a id="x1-40001.3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Initialization Errors</h4>


<!-- l. 59 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">We’ve also seen a large number of initialization errors when updating to smart pointers. Using the
above examples, it’s tempting for a developer to use shortcuts and commit the error demonstrated in
Listing <a href="#x1-4001r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">5<!-- tex4ht:ref: lst:20210412:3  --></a>.
</p>
   

<!-- l. 61 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-4001r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-4002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>
   

<div id="listing-5" class="lstlisting" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-4003r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">shared_ptr&lt;bool&gt; test1 (new bool); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-4004r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">cout &lt;&lt; "Test1 is: " &lt;&lt; *test1 &lt;&lt; endl;</span>
<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 5:</span><span class="content">Uninitialized Boolean</span></figcaption><!-- tex4ht:label?: x1-4001r1  -->
   
</div>


<!-- l. 66 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   The unpredictable nature of this issue can be demonstrated in the example in Listing <a href="#x1-4005r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">6<!-- tex4ht:ref: lst:20210412:4  --></a> where the Boolean uses
default initialization and obtains a random value from previously-freed memory.
</p>
   

<!-- l. 68 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-4005r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-4006" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>
   

<div id="listing-6" class="lstlisting" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-4007r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">#include</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> &lt;climits&gt; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-4008r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">#include</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> &lt;iostream&gt; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-4009r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">#include</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> &lt;memory&gt; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-4010r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">#include</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> &lt;random&gt; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-4011r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">using namespace std; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-4012r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">int</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> main() </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-4013r7" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">{ </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-4014r8" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        random_device rd; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-4015r9" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        mt19937 gen(rd()); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-4016r10" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        uniform_int_distribution&lt;&gt; distrib(INT_MIN, INT_MAX); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-4017r11" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        vector&lt;</span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">int</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">*&gt; deleteLater; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-4018r12" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">for</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> (</span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">int</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> i = 0; i &lt; 100; i++) </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-4019r13" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        { </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-4020r14" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">               </span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">int</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> *deleteMe = new </span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">int</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-4021r15" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">               *deleteMe = distrib(gen); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-4022r16" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtti-10x-x-90" style="font-size: 90%; font-family: monospace,monospace; font-style: italic;">               //delete some memory now</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-4023r17" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">               </span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">if</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> (*deleteMe &gt; 0) </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-4024r18" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">                       delete deleteMe; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-4025r19" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">               </span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">else</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-4026r20" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">                       deleteLater.push_back(deleteMe); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-4027r21" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        } </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-4028r22" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        shared_ptr&lt;bool&gt; newBool(new bool); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-4029r23" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        cout &lt;&lt; "Value: " &lt;&lt; *newBool &lt;&lt; endl; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-4030r24" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtti-10x-x-90" style="font-size: 90%; font-family: monospace,monospace; font-style: italic;">        //delete some memory later</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-4031r25" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">for</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> (</span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">int</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> *n : deleteLater) </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-4032r26" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">               delete n; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-4033r27" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">return</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> 0; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-4034r28" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">}</span>
<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 6:</span><span class="content">Uninitialized Boolean</span></figcaption><!-- tex4ht:label?: x1-4005r1  -->
   
</div>

                                                                                         
                                                                                         

<!-- l. 99 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.4   </span> <a id="x1-50001.4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Inconsistency Can Increase Maintenance Costs</h4>


<!-- l. 101 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Consider updated code that uses a multitude of different memory handling methods. Some memory is managed
manually using <span class="ec-lmtt-10" style="font-family: monospace,monospace;">malloc </span>and <span class="ec-lmtt-10" style="font-family: monospace,monospace;">free</span>. Some pass the previous pointer values to smart pointers for their management.
Others have been updated to use the <span class="ec-lmtt-10" style="font-family: monospace,monospace;">make_shared </span>construct. Still others have been updated to custom classes and
structs.
</p>
<!-- l. 103 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Consistency is more important than updating. Introducing multiple memory handling patterns to a section of
code increases its complexity. If old memory handling methods cannot be replaced or are not planned to be replaced,
it may make more sense to stick with confusing (but consistent) code rather than adding additional
complexity.
</p>
<!-- l. 105 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.5   </span> <a id="x1-60001.5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Smart Pointers and Arrays</h4>


<!-- l. 107 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Finally, some special considerations are needed for allowing smart pointers to handle arrays. The <span class="ec-lmtt-10" style="font-family: monospace,monospace;">shared_ptr</span>
construct permits the developer to define a custom deleter like the one for this array of 10 Booleans:
</p>
   

<!-- l. 109 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-6001r7" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-6002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>
   

<div id="listing-7" class="lstlisting" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-6003r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">shared_ptr&lt;bool&gt; test1{ </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-6004r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        new bool[10], [](</span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">const</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> bool *ptr) { delete [] ptr; } </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-6005r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">};</span>
<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 7:</span><span class="content">Custom Deleter</span></figcaption><!-- tex4ht:label?: x1-6001r1  -->
   
</div>


<!-- l. 115 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.6   </span> <a id="x1-70001.6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Conclusion</h4>


<!-- l. 117 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Smart pointers and RAII concepts help developers prevent memory errors that can plague software. Updating legacy
code to RAII concepts can increase its maintainability, usefulness, and security. Nevertheless, updates to the code
should not come at a price of inconsistency. When updates can only be applied partially or introduce additional
complexity, consistency should be preferred.
                                                                                         
                                                                                         
</p>
   

<h3 class="sectionHead"><a id="x1-80001.6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>References</h3>


<!-- l. 45 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">    
</p>


<dl class="thebibliography"><dt id="X0-swatips" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[1]  
</dt><dd id="bib-1" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 45 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon Hood, ed. <span class="rm-lmri-10" style="font-style: italic;">SwATips</span>. <a class="url" href="https://www.SwATips.com/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.SwATips.com/</span></a>.
</p>    
</dd>
<dt id="X0-20210412-stroustrup2001" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[2]  
</dt><dd id="bib-2" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 45 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20210412-stroustrup2001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Bjarne    Stroustrup.    “Exception    Safety:    Concepts    and    Techniques”.    In:    (2001).    <span class="small-caps" style="font-variant: small-caps;">url</span>:
<a class="url" href="https://www.stroustrup.com/except.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.stroustrup.com/except.pdf</span></a>.</p></dd></dl>

 

]]></description>
	</item>
	<item>
		<title>COTS, GOTS, and NOTS software in RMF for the Army</title>
		<link>https://www.SwATips.com/articles/20210405.html</link>
		<pubDate>Mon, 05 Apr 2021 00:00:00 -0500</pubDate>
<description><![CDATA[

<p style="margin-top: 0; margin-bottom: 0;">Return to <a href="/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">SwATips</a> | <a href="articles/20210405.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">pdf</a> | <a rel="license" href="http://creativecommons.org/licenses/by/4.0/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/by.svg" width="60" height="21" alt="CC-BY" style="border-top: 0; border-left: 0; border-right: 0;"/></a></p>


<div class="maketitle" style="margin-top: 1em; text-align: center; margin-bottom: 2em;">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead" style="text-align: center;"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a href="#cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2</a>]<br/>
Generated Friday 7<sup class="textsuperscript">th</sup> May, 2021</h2>
<div class="author" style="text-align: center;"><span class="rm-lmr-12" style="font-size: 120%;">Jon Hood</span></div><br/>
<div class="date" style="text-align: center;"><span class="rm-lmr-12" style="font-size: 120%;">Monday 5</span><sup class="textsuperscript"><span class="rm-lmr-9" style="font-size: 90%;">th</span></sup><span class="rm-lmr-12" style="font-size: 120%;"> April, 2021</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead"><span class="titlemark">1   </span> <a id="x1-10001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>COTS, GOTS, and NOTS software in RMF for the Army</h3>


<!-- l. 1 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">When working as a government contractor security professional for a system that includes custom software, three
different classes of software must be considered as part of the RMF process: </p>


<ul class="itemize1">     
<li class="itemize">COTS—Commercial Off-The-Shelf
</li>     
<li class="itemize">GOTS—Government Off-The-Shelf
</li>     
<li class="itemize">NOTS—Not Off-The-Shelf</li></ul>


<!-- l. 8 -->
<p class="indent" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   A compliant Risk Management Framework (RMF) software list or Software Bill of Materials (S-BoM) manages
the different approval paths for these types of software.
</p>
<!-- l. 10 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.1   </span> <a id="x1-20001.1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Identifying the Software</h4>


<!-- l. 12 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">COTS software includes any software built for non-government, public activity. While COTS software implies a
commercial aspect to the application, open-source and public domain software are also included in the definition of
COTS software. While Shareware, Freeware, Adware, and as-is trial software are also COTS, they require explicit
Army SISO approval on each system they’re installed on and are not considered as part of this article.[<a href="#cite.0@20210405-ar25-2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">3</a>, 4–12.a.6]
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
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   GOTS software is software that is not sold commercially or provided publicly. It is software created for or owned
by a government agency. This doesn’t mean that commercial/contractor providers don’t own the software. GOTS
software falls into three sub-categories:
</p>
     

<ol class="enumerate1" style="list-style-type: decimal;">
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
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.2   </span> <a id="x1-30001.2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Assessing the Software</h4>


<!-- l. 23 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">COTS products can be assessed in multiple ways: </p>


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
<p class="indent" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   When filling out the ASD STIG for COTS software, several of the checks deal with a development environment
that is not geared towards developing the software for a government environment. Checks that pertain to
development processes and requirements can be marked as Not Applicable because the COTS software has
already been selected because it fulfills a requirements for a particular mission. If a mission dictates
new requirements that require custom development, that development should consider falling under
GOTS.
</p>
<!-- l. 36 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   For GOTS software, the software is first assessed for compliance from a legal perspective: </p>


<ul class="itemize1">     
<li class="itemize">Is the software in the public domain with source code available?
</li>     
<li class="itemize">Does  the  software  meet  the  definition  of  “computer  software”  under  GOTS  Fdederal  Acquisition
Regulation (FAR) definitions?</li></ul>


<!-- l. 41 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">If the software is GOTS, you will have the entirety of instructions for how to build the software. This is the legal
definition of GOTS. If you cannot build the software or are not provided the source code, the software does not meet
the definition of GOTS computer software per the FAR.
</p>
<!-- l. 43 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Once the software has been identified as GOTS, the ASD STIG is evaluated and any relevant SA-11 controls are
tailored in to the RMF control selection.
</p>
<!-- l. 45 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   There is a final class of software that pretends to be GOTS but does not provide source code or build
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
<!-- l. 46 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;">(i) A commercial item...;<br class="newline"/>(ii) Sold in substantial quantities in the commercial marketplace; and<br class="newline"/>(iii) Offered to the Government, under a contract or subcontract at any tier, without modification,
in the same form in which it is sold in the commercial marketplace;...[<a href="#cite.0@20210405-far" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1</a>]</p></blockquote>


<!-- l. 50 -->
<p class="indent" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   A piece of software that is not sold in a public, commercial marketplace is not COTS. Likewise, software that
does not provide source code and build instructions is not GOTS. These software packages are non-COTS,
non-GOTS, and simply ”not off-the-shelf” NOTS software that must have explicit AO approval and be tracked using
non-FAR-compliant acquisition processes.
</p>
<!-- l. 52 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Nevertheless, there is a non-trivial amount of NOTS software that is in use by the Army. Our
recommendation: perform a best-effort SwA scan, but also mark high-risk findings against the following checklists:
</p>
     

<ul class="itemize1">
<li class="itemize">On the ASD STIG, mark SV-222658r508029_rule (as of ASD V5R1) as a finding with the comment,
“The  support  contract  does  not  meet  the  requirements  of  COTS,  nor  does  the  application  meet
the definition of Computer Software for GOTS. COTS software must be procured through proper
acquisition channels (<a class="url" href="https://www.acquisition.gov/content/2101-definitions#i1125359" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.acquisition.gov/content/2101-definitions#i1125359</span></a>), and
GOTS computer software must provide source code and build instructions (48 CFR § 252.227-7014).”
</li>     
<li class="itemize">Tailor  in  (if  not  already  in  the  baseline)  and  mark  as  NON-COMPLIANT  RMF  control  SA-22,
CCI-3376 with the comment, “A software package does not provide either COTS or GOTS support
mechanisms.”
</li>     
<li class="itemize">Tailor in (if not already in the baseline) and mark as NON-COMPLIANT RMF control SA-4 (6),
CCI-631 with the comment, “The system employs software that is not COTS or GOTS.”</li></ul>


<!-- l. 59 -->
<p class="indent" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   Note that RMF CCI-631 requires your software solutions to be either COTS or GOTS: “The organization
employs only government off-the-shelf (GOTS) or commercial off-the-shelf (COTS) information assurance (IA) and
IA-enabled information technology products that compose an NSA-approved solution to protect classified
information when the networks used to transmit the information are at a lower classification level than the
information being transmitted.” By attaching a finding to CCI-631, the program must include the finding in their
POA&amp;M for tracking and obtain AO approval for the non-compliant software.
                                                                                         
                                                                                         
</p>
   

<h3 class="sectionHead"><a id="x1-40001.2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>References</h3>


<!-- l. 45 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">    
</p>


<dl class="thebibliography"><dt class="thebibliography" id="X0-20210405-far" style="float: left; clear: left; margin-right: 1em;">
[1]  
</dt><dd class="thebibliography" id="bib-1" style="margin-left: 2.5em;">
<!-- l. 45 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20210405-far" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>GSA.    <span class="rm-lmri-10" style="font-style: italic;">Federal   Acuisition   Regulation.   Definitions</span>.    Department    of    Defense.    2019.    <span class="small-caps" style="font-variant: small-caps;">url</span>:
<a class="url" href="https://www.acquisition.gov/far/2.101" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.acquisition.gov/far/2.101</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-swatips" style="float: left; clear: left; margin-right: 1em;">
[2]  
</dt><dd class="thebibliography" id="bib-2" style="margin-left: 2.5em;">
<!-- l. 45 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon Hood, ed. <span class="rm-lmri-10" style="font-style: italic;">SwATips</span>. <a class="url" href="https://www.SwATips.com/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.SwATips.com/</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-20210405-ar25-2" style="float: left; clear: left; margin-right: 1em;">
[3]  
</dt><dd class="thebibliography" id="bib-3" style="margin-left: 2.5em;">
<!-- l. 45 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20210405-ar25-2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>HQDA. <span class="rm-lmri-10" style="font-style: italic;">Army Regulation 25–2. Information Management: Information Assurance</span>. Department of the
Army.                 Washington,                 DC,                 USA,                 2019.                 <span class="small-caps" style="font-variant: small-caps;">url</span>:
<a class="url" href="https://armypubs.army.mil/epubs/DR_pubs/DR_a/pdf/web/ARN17503_AR25_2_Admin_FINAL.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://armypubs.army.mil/epubs/DR_pubs/DR_a/pdf/web/ARN17503_AR25_2_Admin_FINAL.pdf</span></a>.</p></dd></dl>

 

]]></description>
	</item>
