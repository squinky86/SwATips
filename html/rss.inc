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
<p class="noindent" style="margin-top: 0; margin-bottom: 0;"><span class="ec-lmr-8" style="font-size: 80%;">Updated Thursday 6</span><sup class="textsuperscript"><span class="ec-lmr-9" style="font-size: 90%;">th</span></sup><span class="ec-lmr-8" style="font-size: 80%;"> June, 2024</span>
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
<li class="itemize">Another organization used SonarQube to scan Ada code.
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
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   As ISSMs and Authorizing Officials continue to mature in zero trust training guidelines, the “minimal
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
<!-- l. 50 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20240610:jackson" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Eric     Jackson.     “When     Zero     Trust     Makes     Zero     Sense”.     In:     (2024).     <span class="small-caps" style="font-variant: small-caps;">url</span>:     
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
<!-- l. 50 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20240610:cio" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Office of the Chief Information Officer. “Department of Defense Zero Trust Overlays”. In: (2024). <span class="small-caps" style="font-variant: small-caps;">url</span>: 
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
	<item>
		<title>Coverity BAD_CAST</title>
		<link>https://www.SwATips.com/articles/20230403.html</link>
		<pubDate>Mon, 03 Apr 2023 00:00:00 -0500</pubDate>
<description><![CDATA[

<p style="margin-top: 0; margin-bottom: 0;"><a href="/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/swatips.svg" width="120" alt="SwATips" style="border-top: 0; border-left: 0; border-right: 0;"/></a>| <a href="articles/20230403.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">pdf</a> | <a rel="license" href="http://creativecommons.org/licenses/by/4.0/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/by.svg" width="60" height="21" alt="CC-BY" style="border-top: 0; border-left: 0; border-right: 0;"/></a></p>


<div class="maketitle" style="margin-top: 1em; text-align: center; margin-bottom: 2em;">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead" style="text-align: center;"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a id="x1-3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1</a>]<br/>
</h2>
<div class="author" style="text-align: center;"><span class="ec-lmr-12" style="font-size: 120%;">Kevin Keen</span></div><br/>
<div class="date" style="text-align: center;"><span class="ec-lmr-12" style="font-size: 120%;">Monday 3</span><sup class="textsuperscript"><span class="ec-lmr-9" style="font-size: 90%;">rd</span></sup><span class="ec-lmr-12" style="font-size: 120%;"> April, 2023</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead" id="coverity-badcast"><span class="titlemark">1   </span> <a id="x1-10001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Coverity BAD_CAST</h3>


<!-- l. 44 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;"><span class="ec-lmr-8" style="font-size: 80%;">Updated Friday 12</span><sup class="textsuperscript"><span class="ec-lmr-9" style="font-size: 90%;">th</span></sup><span class="ec-lmr-8" style="font-size: 80%;"> May, 2023</span>
</p>
<!-- l. 1 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Recently we came across a finding in a Coverity scan that was a bit puzzling at first. The finding was labeled
<span class="ec-lmtt-10" style="font-family: monospace,monospace;">BAD_CAST</span>. The supporting details didn’t help much either. It simply indicated a conversion between incompatible
types. There are probably several different reasons Coverity might flag this issue. The line of code in question this
time was attempting to start a new thread by calling <span class="ec-lmtt-10" style="font-family: monospace,monospace;">pthread_create</span>. As is expected with <span class="ec-lmtt-10" style="font-family: monospace,monospace;">pthread_create</span>, they
were attempting to pass a pointer to a function that would be called as the thread started. That much is normal
when using pthreads. Listing <a href="#x1-1001r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1<!-- tex4ht:ref: lst:20230403:ptr1  --></a> illustrates a fairly normal use of <span class="ec-lmtt-10" style="font-family: monospace,monospace;">pthread_create </span>using a non member function
pointer as the callback.
</p>
   

<!-- l. 3 -->


<p id="-typical-use-of-a-function-poiter" style="margin-bottom: 0; margin-top: 1em;"><a id="x1-1001r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>
<a id="x1-1002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>   
</p>
<pre class="lstlisting" id="listing-1" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-1003r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">#</span></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">include</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">&lt;pthread.h&gt;</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1004r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">#</span></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">include</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">&lt;iostream&gt;</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1005r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1006r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">using</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">namespace </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">std;</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1007r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1008r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">void</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">*</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">non_member_function(</span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">void</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">* </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">foo) </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">{</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1009r7" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">cout</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">&lt;&lt; </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">"In </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">non_member_function!" </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">&lt;&lt; </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">endl;</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1010r8" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">}</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1011r9" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1012r10" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">int</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">main(</span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">int </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">argc, </span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">char</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">** </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">argv) </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">{</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1013r11" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">pthread_t</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">thread;</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1014r12" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1015r13" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">pthread_create</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">(&amp;</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">thread</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">,</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">NULL, </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">&amp;non_member_function, </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">NULL);</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1016r14" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1017r15" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">pthread_join</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">(</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">thread</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">,</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">NULL);</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1018r16" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1019r17" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">return</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">0;</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1020r18" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">}</span></span></pre>


<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 1: </span><span class="content">Typical Use of a Function Poiter</span></figcaption>
<!-- tex4ht:label?: x1-1020r1  -->


<!-- l. 24 -->
<p class="indent" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   Where things went wrong was that the pointer being passed was a <span class="ec-lmtt-10" style="font-family: monospace,monospace;">reinterpret_cast </span>of the address of a
member function. Listing <a href="#x1-1021r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2<!-- tex4ht:ref: lst:20230403:ptr2  --></a> shows an example of attempting to pass a member function pointer to <span class="ec-lmtt-10" style="font-family: monospace,monospace;">pthread_create</span>.
Don’t do this!!!
</p>
   

<!-- l. 26 -->


<p id="-improper-use-of-a-pointer-to-a-member-function" style="margin-bottom: 0; margin-top: 1em;"><a id="x1-1021r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>
<a id="x1-1022" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>   
</p>
<pre class="lstlisting" id="listing-2" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-1023r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">#</span></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">include</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">&lt;pthread.h&gt;</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1024r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">#</span></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">include</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">&lt;iostream&gt;</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1025r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1026r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">using</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">namespace </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">std;</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1027r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1028r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">class</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">Example </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">{</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1029r7" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">public</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">:</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1030r8" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">               </span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">void</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">*</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">member_function(</span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">void</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">* </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">foo);</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1031r9" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">};</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1032r10" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1033r11" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">void</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">*</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">Example::member_function(</span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">void</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">* </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">foo) </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">{</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1034r12" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">cout</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">&lt;&lt; </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">"In </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">member_function!" </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">&lt;&lt; </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">endl;</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1035r13" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">}</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1036r14" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1037r15" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">int</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">main(</span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">int </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">argc, </span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">char</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">** </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">argv) </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">{</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1038r16" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">pthread_t</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">thread;</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1039r17" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1040r18" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">pthread_create</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">(&amp;</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">thread</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">,</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">NULL, </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">reinterpret_cast&lt;</span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">void</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">*(*)(</span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">void</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">*)&gt;(&amp;Example::member_function, </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">NULL);</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1041r19" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1042r20" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">pthread_join</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">(</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">thread</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">,</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">NULL);</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1043r21" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1044r22" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">return</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">0;</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1045r23" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">}</span></span></pre>


<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 2: </span><span class="content">Improper Use of a Pointer to a Member Function</span></figcaption>
<!-- tex4ht:label?: x1-1045r1  -->


<!-- l. 52 -->
<p class="indent" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   In C++, function pointers differ from pointers to member functions. A pointer to a member function might
actually be represented by a data structure containing extra information, especially if it were pointing at a virtual
function.[<a id="x1-1046" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@20230403:ptm" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2</a>] In fact, there is so much difference between normal function pointers and pointers to member functions
that there is even special syntax for declaring a pointer to a member function. Listing <a href="#x1-1047r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">3<!-- tex4ht:ref: lst:20230403:ptr3  --></a> shows an example of
declaring and using a pointer to a member function. Listing <a href="#x1-1070r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">4<!-- tex4ht:ref: lst:20230403:ptr4  --></a> shows another example, improved with the use of a
<span class="ec-lmtt-10" style="font-family: monospace,monospace;">typedef</span>.
</p>
   

<!-- l. 54 -->


<p id="-example-of-declaring-and-using-a-pointer-to-a-member-function" style="margin-bottom: 0; margin-top: 1em;"><a id="x1-1047r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>
<a id="x1-1048" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>   
</p>
<pre class="lstlisting" id="listing-3" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-1049r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">#</span></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">include</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">&lt;iostream&gt;</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1050r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1051r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">using</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">namespace </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">std;</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1052r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1053r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">class</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">Example </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">{</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1054r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">public</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">:</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1055r7" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">               </span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">void</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">*</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">member_function(</span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">void</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">* </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">foo);</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1056r8" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">};</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1057r9" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1058r10" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">void</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">*</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">Example::member_function(</span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">void</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">* </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">foo) </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">{</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1059r11" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">cout</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">&lt;&lt; </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">"In </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">member_function!" </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">&lt;&lt; </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">endl;</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1060r12" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">}</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1061r13" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1062r14" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">int</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">main(</span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">int </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">argc, </span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">char</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">** </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">argv) </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">{</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1063r15" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">Example</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">myExample;</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1064r16" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1065r17" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">void</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">*</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">(Example::*memFuncPtr)(</span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">void</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">*) </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">= </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">&amp;Example::member_function;</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1066r18" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">(</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">myExample</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">.*</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">memFuncPtr</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">)(</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">NULL</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">);</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1067r19" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1068r20" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">return</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">0;</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1069r21" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">}</span></span></pre>


<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 3: </span><span class="content">Example of Declaring and Using a Pointer to a Member Function</span></figcaption>
<!-- tex4ht:label?: x1-1069r1  -->

   

<!-- l. 77 -->


<p id="-use-of-typedef-with-pointer-to-member-function-to-improve-readability" style="margin-top: 0; margin-bottom: 0;"><a id="x1-1070r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>
<a id="x1-1071" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>   
</p>
<pre class="lstlisting" id="listing-4" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-1072r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">#</span></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">include</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">&lt;iostream&gt;</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1073r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1074r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">using</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">namespace </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">std;</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1075r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1076r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">class</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">Example </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">{</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1077r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">public</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">:</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1078r7" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">               </span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">void</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">*</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">member_function(</span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">void</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">* </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">foo);</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1079r8" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">};</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1080r9" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1081r10" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">void</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">*</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">Example::member_function(</span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">void</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">* </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">foo) </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">{</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1082r11" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">cout</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">&lt;&lt; </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">"In </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">member_function!" </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">&lt;&lt; </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">endl;</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1083r12" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">}</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1084r13" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1085r14" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">int</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">main(</span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">int </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">argc, </span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">char</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">** </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">argv) </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">{</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1086r15" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">Example</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">myExample;</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1087r16" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1088r17" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">typedef</span></span><span style="color:#000000"> <span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">void</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">* </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">(Example::*memFuncPtr)(</span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">void</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">*);</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1089r18" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">memFuncPtr</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">myPtr </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">= </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">&amp;Example::member_function;</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1090r19" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">(</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">myExample</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">.*</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">myPtr</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">)(</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">NULL</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">);</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1091r20" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1092r21" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">return</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">0;</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1093r22" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">}</span></span></pre>


<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 4: </span><span class="content">Use of Typedef with Pointer to Member Function to Improve Readability</span></figcaption>
<!-- tex4ht:label?: x1-1093r1  -->


<!-- l. 102 -->
<p class="indent" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   A non-static member function can’t really exist on its own. It is part of a class and must exist as part of that
class. Trying to invoke it apart from the class being instantiated doesn’t make much sense (unless the function is
declared static[<a href="#cite.0@20230403:ptm" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2</a>]). Note that in the example code in Listings <a href="#x1-1047r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">3<!-- tex4ht:ref: lst:20230403:ptr3  --></a> and <a href="#x1-1070r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">4<!-- tex4ht:ref: lst:20230403:ptr4  --></a>, we had to use an object (<span class="ec-lmtt-10" style="font-family: monospace,monospace;">myExample</span>) in order
to invoke the member function through the pointer.
                                                                                         
                                                                                         
</p>
<!-- l. 104 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Good compilers will give a warning if you try to cast a pointer to a member function into a regular function
pointer, but will normally allow you to do so anyway. Even <strong><i>IF</i></strong> it happens to work as expected when tested, doing
this is strictly in the land of undefined behavior. It is not guaranteed to work, not portable, and could break in the
most spectacular fashion at any point in the future.
</p>
<!-- l. 106 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   If you find yourself in this situation, take heart! There is a solution! Simply have a non-member function as an
intermediate step. That intermediate function can take a pointer or reference to the desired object and call the
member method. And because it is a non-member function itself, it is safe to create a function pointer that can be
passed to functions like <span class="ec-lmtt-10" style="font-family: monospace,monospace;">pthread_create</span>. Problem solved!
</p>
   

<!-- l. 108 -->


<p id="-using-an-intermediate-function" style="margin-bottom: 0; margin-top: 1em;"><a id="x1-1094r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>
<a id="x1-1095" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>   
</p>
<pre class="lstlisting" id="listing-5" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-1096r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">#</span></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">include</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">&lt;pthread.h&gt;</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1097r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">#</span></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">include</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">&lt;iostream&gt;</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1098r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1099r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">using</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">namespace </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">std;</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1100r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1101r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">class</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">Example </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">{</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1102r7" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">public</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">:</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1103r8" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">               </span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">void</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">*</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">member_function(</span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">void</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">* </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">foo);</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1104r9" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">};</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1105r10" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1106r11" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">void</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">*</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">Example::member_function(</span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">void</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">* </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">foo) </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">{</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1107r12" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">cout</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">&lt;&lt; </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">"In </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">member_function!" </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">&lt;&lt; </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">endl;</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1108r13" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">}</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1109r14" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1110r15" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">void</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">*</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">intermediate_func(</span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">void</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">* </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">objPtr) </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">{</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1111r16" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">Example</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">*</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">examplePtr </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">= </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">(Example*)objPtr;</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1112r17" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">examplePtr</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">-&gt;</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">member_function</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">(</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">NULL</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">);</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1113r18" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">}</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1114r19" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1115r20" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">int</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">main(</span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">int </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">argc, </span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">char</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">** </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">argv) </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">{</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1116r21" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">Example</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">myExample;</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1117r22" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1118r23" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">pthread_t</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">thread;</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1119r24" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1120r25" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">pthread_create</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">(&amp;</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">thread</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">,</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">NULL, </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">&amp;intermediate_func, </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">myExample);</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1121r26" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1122r27" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">pthread_join</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">(</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">thread</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">,</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">NULL);</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1123r28" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1124r29" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">return</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">0;</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1125r30" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">}</span></span></pre>


<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 5: </span><span class="content">Using an Intermediate Function</span></figcaption>
<!-- tex4ht:label?: x1-1125r1  -->

                                                                                         
                                                                                         
   

<h3 class="sectionHead" id="references"><a id="x1-20001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>References</h3>


<!-- l. 49 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">    
</p>


<dl class="thebibliography"><dt class="thebibliography" id="X0-swatips" style="float: left; clear: left; margin-right: 1em;">
[1]  
</dt><dd class="thebibliography" id="bib-1" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon Hood, ed. SwATips.     <a class="url" href="https://www.SwATips.com/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.SwATips.com/</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-20230403:ptm" style="float: left; clear: left; margin-right: 1em;">
[2]  
</dt><dd class="thebibliography" id="bib-2" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20230403:ptm" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Standard       C++       Foundation.       “Pointers       to       Members”.       In:       ().       <span class="small-caps" style="font-variant: small-caps;">url</span>:
<a class="url" href="https://isocpp.org/wiki/faq/pointers-to-members" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://isocpp.org/wiki/faq/pointers-to-members</span></a>.</p></dd></dl>

 

]]></description>
	</item>
	<item>
		<title>Java, Inner Classes, and Checkmarx Unused Variable Findings</title>
		<link>https://www.SwATips.com/articles/20221017.html</link>
		<pubDate>Mon, 17 Oct 2022 00:00:00 -0500</pubDate>
<description><![CDATA[

<p style="margin-top: 0; margin-bottom: 0;"><a href="/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/swatips.svg" width="120" alt="SwATips" style="border-top: 0; border-left: 0; border-right: 0;"/></a>| <a href="articles/20221017.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">pdf</a> | <a rel="license" href="http://creativecommons.org/licenses/by/4.0/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/by.svg" width="60" height="21" alt="CC-BY" style="border-top: 0; border-left: 0; border-right: 0;"/></a></p>


<div class="maketitle" style="margin-top: 1em; text-align: center; margin-bottom: 2em;">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead" style="text-align: center;"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a id="x1-3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1</a>]<br/>
</h2>
<div class="author" style="text-align: center;"><span class="ec-lmr-12" style="font-size: 120%;">Kevin Keen</span></div><br/>
<div class="date" style="text-align: center;"><span class="ec-lmr-12" style="font-size: 120%;">Monday 17</span><sup class="textsuperscript"><span class="ec-lmr-9" style="font-size: 90%;">th</span></sup><span class="ec-lmr-12" style="font-size: 120%;"> October, 2022</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead" id="java-inner-classes-and-checkmarx-unused-variable-findings"><span class="titlemark">1   </span> <a id="x1-10001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Java, Inner Classes, and Checkmarx Unused Variable Findings</h3>


<!-- l. 44 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;"><span class="ec-lmr-8" style="font-size: 80%;">Updated Friday 14</span><sup class="textsuperscript"><span class="ec-lmr-9" style="font-size: 90%;">th</span></sup><span class="ec-lmr-8" style="font-size: 80%;"> October, 2022</span>
</p>
<!-- l. 1 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Java has some odd, non-intuitive rules when it comes to the visibility of inner classes. One of which is that an
inner class not marked <span class="ec-lmtt-10" style="font-family: monospace,monospace;">private </span>will be accessible to other classes in the same package. This can lead to some odd
code that Checkmarx doesn’t handle well, especially when the inner class is a POD (plain old data)
class.
</p>
<!-- l. 3 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   A good argument can be made that Java applications really shouldn’t have many, if any, POD classes. After all,
data exists to be operated on, and if there is behavior defined somewhere to operate on this data, why not have it
live in the same place? Nevertheless, POD classes do tend to creep their way into some Java applications,
particularly if the programmer hails from a C background and is accustomed to working with structs. While
avoiding POD classes might prevent the issue we are about to highlight, we will set the POD v. no-POD debate
aside for the time being.
</p>
<!-- l. 5 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   When an inner class is not declared <span class="ec-lmtt-10" style="font-family: monospace,monospace;">private</span>, it is entirely possible for members of that class to be unused
locally, in any of its sibling classes, or in the enclosing class. Instead, because of the package level visibility, the use
may reside in a completely different class. Take, for example, a class <span class="ec-lmtt-10" style="font-family: monospace,monospace;">Outer</span>, which contains a private (no
public, protected, etc) class <span class="ec-lmtt-10" style="font-family: monospace,monospace;">Inner</span>. A 3<sup class="textsuperscript"><span class="ec-lmr-9" style="font-size: 90%;">rd</span></sup> unrelated class could then contain code like that shown in
Listing <a href="#x1-1001r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1<!-- tex4ht:ref: lst:20221017:unusedinner  --></a>.
</p>
   

<!-- l. 7 -->


<p id="-tertiary-class-with-unused-inner-variables" style="margin-bottom: 0; margin-top: 1em;"><a id="x1-1001r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>
<a id="x1-1002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>   
</p>
<pre class="lstlisting" id="listing-1" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-1003r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">(</span></span><span style="color:#000000"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">In</span></span><span style="color:#000000"> <span class="ec-lmtk-10" style="font-family: monospace,monospace;">class </span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">Unrelated)</span></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1004r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">Outer</span></span><span style="color:#000000"> <span class="ec-lmtt-10" style="font-family: monospace,monospace;">myOuter </span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">= </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">new </span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">Outer();</span></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1005r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">Inner</span></span><span style="color:#000000"> <span class="ec-lmtt-10" style="font-family: monospace,monospace;">myInner </span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">= </span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">myOuter.</span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">new </span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">Inner();</span></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1006r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10" style="font-family: monospace,monospace;">if</span></span><span style="color:#000000"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">(</span></span><span style="color:#000000"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">myInner</span></span><span style="color:#000000"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">.</span></span><span style="color:#000000"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">thoughtItWasUnused</span></span><span style="color:#000000"> <span class="ec-lmtt-10" style="font-family: monospace,monospace;">== </span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">5) </span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">{</span></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">… </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1007r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-1008r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">}</span></span></pre>


<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 1: </span><span class="content">Tertiary Class with Unused Inner Variables</span></figcaption>
<!-- tex4ht:label?: x1-1008r1  -->


<!-- l. 16 -->
<p class="indent" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   Unfortunately, in these cases, Checkmarx is likely to flag the members of <span class="ec-lmtt-10" style="font-family: monospace,monospace;">Inner </span>as unused variables unless they
are used by either the <span class="ec-lmtt-10" style="font-family: monospace,monospace;">Inner </span>class itself or perhaps by <span class="ec-lmtt-10" style="font-family: monospace,monospace;">Outer</span>. In this example, the member <span class="ec-lmtt-10" style="font-family: monospace,monospace;">thoughtItWasUnused</span>
may have been flagged in <span class="ec-lmtt-10" style="font-family: monospace,monospace;">Outer.java </span>as an unused variable.
                                                                                         
                                                                                         
</p>
   

<h3 class="sectionHead" id="references"><a id="x1-20001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>References</h3>


<!-- l. 49 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">    
</p>


<dl class="thebibliography"><dt class="thebibliography" id="X0-swatips" style="float: left; clear: left; margin-right: 1em;">
[1]  
</dt><dd class="thebibliography" id="bib-1" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon Hood, ed. SwATips.     <a class="url" href="https://www.SwATips.com/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.SwATips.com/</span></a>.</p></dd></dl>

 

]]></description>
	</item>
	<item>
		<title>Commercial National Security Algorithm (CNSA) Suite 2.0</title>
		<link>https://www.SwATips.com/articles/20220919.html</link>
		<pubDate>Mon, 19 Sep 2022 00:00:00 -0500</pubDate>
<description><![CDATA[

<p style="margin-top: 0; margin-bottom: 0;"><a href="/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/swatips.svg" width="120" alt="SwATips" style="border-top: 0; border-left: 0; border-right: 0;"/></a>| <a href="articles/20220919.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">pdf</a> | <a rel="license" href="http://creativecommons.org/licenses/by/4.0/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/by.svg" width="60" height="21" alt="CC-BY" style="border-top: 0; border-left: 0; border-right: 0;"/></a></p>


<div class="maketitle" style="margin-top: 1em; text-align: center; margin-bottom: 2em;">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead" style="text-align: center;"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a id="x1-3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2</a>]<br/>
</h2>
<div class="author" style="text-align: center;"><span class="ec-lmr-12" style="font-size: 120%;">Jon Hood</span></div><br/>
<div class="date" style="text-align: center;"><span class="ec-lmr-12" style="font-size: 120%;">Monday 19</span><sup class="textsuperscript"><span class="ec-lmr-9" style="font-size: 90%;">th</span></sup><span class="ec-lmr-12" style="font-size: 120%;"> September, 2022</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead" id="commercial-national-security-algorithm-cnsa-suite-"><span class="titlemark">1   </span> <a id="x1-10001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Commercial National Security Algorithm (CNSA) Suite 2.0</h3>


<!-- l. 44 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;"><span class="ec-lmr-8" style="font-size: 80%;">Updated Friday 23</span><sup class="textsuperscript"><span class="ec-lmr-9" style="font-size: 90%;">rd</span></sup><span class="ec-lmr-8" style="font-size: 80%;"> September, 2022</span>
</p>
<!-- l. 1 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   As the government switches to quantum-resistant and post-quantum cryptographic algorithms, the CNSA suite
(formerly Suite-B algorithms) is undergoing some changes with a new release: version 2.0. This release of the CNSA
suite includes the following information:[<a id="x1-1001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@20220919:cnsa" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">3</a>] </p>


<ul class="itemize1">     
<li class="itemize">a requirement to be compliant and support these algorithms by 2035
</li>
<li class="itemize">     
<!-- l. 4 --><p class="noindent" style="margin-top: 0em; margin-bottom: 0;">a requirement to use NIST 800-208 for application signing which includes: </p>
<ul class="itemize2" style="margin-bottom: 0.5em;">         
<li class="itemize">a recommendation to use at least LMS with the SHA-256/192 parameters or XMSS with any
parameters
</li>
<li class="itemize">deprecation of all other algorithms by 2025 (2030 for current deployments)</li></ul>
</li>     
<li class="itemize">a requirement to use FIPS PUB 197 for symmetric block cipher encryption, requiring 256-bit keys (systems
should already be doing this)
</li>
<li class="itemize">a requirement to use FIPS PUB 180-4 for hashing, requiring either the SHA-384 or SHA-512 algorithms
(systems should already be doing this)
</li>
<li class="itemize">a requirement to use CRYSTALS-Kyber for public-key encryption, requiring Level V parameters and a
deprecation of RSA, DH, and ECC once implemented by 2035
</li>
<li class="itemize">a requirement to use CRYSTALS-Dilithium for digital signatures by 2035</li></ul>


<!-- l. 15 -->
<p class="indent" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   Navigating these new requirements imposes a technical hurdle, and acquisition managers should prepare for this
move in their timelines. This article attempts to help explain the requirements at a technical level to help drive the
transition. At the time of this writing, the algorithms in CNSA 2.0 are not included in any mainline cryptography
libraries. For the examples, the Open Quantum Safe (OQS) Project OpenSSL 1.1.1-stable snapshot 2022-08 (
<a class="url" href="https://github.com/open-quantum-safe/openssl/releases/tag/OQS-OpenSSL-1_1_1-stable-snapshot-2022-08" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://github.com/open-quantum-safe/openssl/releases/tag/OQS-OpenSSL-1_1_1-stable-snapshot-2022-08</span></a>)
is used on a vanilla Ubuntu 22.04 installation, and the reference implementations for all algorithms are used for key
implementation.
                                                                                         
                                                                                         
</p>
<!-- l. 17 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead" id="software-and-firmware-signing"><span class="titlemark">1.1   </span> <a id="x1-20001.1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Software and Firmware Signing</h4>


<!-- l. 18 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Software and firmware signing can begin transitioning to CNSA 2.0 immediately with plans to retire CNSA 1.0
support.
</p>
   

<div class="table" style="margin-top: 1em;">
                                                                                         
                                                                                         
<!-- l. 21 --><p class="indent" id="-software-and-firmware-signing-algorithms-cnsa-vs-" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   <a id="x1-20011" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p><figure class="float" style="margin-left: auto; margin-right: auto;">
                                                                                         
                                                                                         
<div class="tabular" style="text-align: center; margin-top: 0.5em; margin-bottom: 0.5em;"> <table class="tabular" id="TBL-2" style="border-collapse: collapse; border-spacing: 0; margin-left: auto; margin-right: auto;"><colgroup id="TBL-2-1g"><col id="TBL-2-1" style="border-left: 1px solid black; border-right: 1px solid black;"/></colgroup><colgroup id="TBL-2-2g"><col id="TBL-2-2" style="border-right: 1px solid black;"/></colgroup><tr class="hline" style="border-top: 1px solid black;"><td style="padding: 0;"/><td style="padding: 0;"/></tr><tr id="TBL-2-1-" style="vertical-align:baseline;"><td class="td11" id="TBL-2-1-1" style="padding-left: 5pt; padding-right: 5pt; white-space: normal; text-align: left;" align="left"><!-- l. 23 --><p class="noindent" style="margin-bottom: 0em; margin-top: 0em;"><strong>CNSA 1.0</strong>                                                </p></td>
                                               <td class="td11" id="TBL-2-1-2" style="padding-left: 5pt; padding-right: 5pt; white-space: normal; text-align: left;" align="left"><!-- l. 23 --><p class="noindent" style="margin-bottom: 0em; margin-top: 0em;"><strong>CNSA 2.0</strong>                                                </p></td></tr><tr class="hline" style="border-top: 1px solid black;"><td style="padding: 0;"/><td style="padding: 0;"/></tr><tr id="TBL-2-2-" style="vertical-align:baseline;"><td class="td 11" id="TBL-2-2-1" style="white-space:normal; text-align:left;"><!-- l. 25 --><p class="noindent" style="margin-bottom: 0em; margin-top: 0em;">Elliptic Curve Digital Signature Algorithm (ECDSA)
using P-384<br class="newline"/>Rivest-Shamir-Adleman    (RSA)    using    minimum
3072-bit modulus                                                 </p></td>
                                               <td class="td11" id="TBL-2-2-2" style="padding-left: 5pt; padding-right: 5pt; white-space: normal; text-align: left;" align="left"><!-- l. 25 --><p class="noindent" style="margin-bottom: 0em; margin-top: 0em;">Leighton-Micali Signature (LMS)<br class="newline"/>Xtended Merkle Signature Scheme (XMSS)             </p></td>
</tr><tr class="hline" style="border-top: 1px solid black;"><td style="padding: 0;"/><td style="padding: 0;"/></tr></table></div>
<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Table 1: </span><span class="content">Software and Firmware Signing Algorithms: CNSA 1.0 vs 2.0</span></figcaption><!-- tex4ht:label?: x1-20011  -->
                                                                                         
                                                                                         
   
</figure>
</div>


<!-- l. 31 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Current PKI infrastructure in the DoD only supports using RSA for digital signatures. Nevertheless, the LMS
reference implementation includes LMS key generation and signature verification for LMS with SHA-256, one of the
permitted signature algorithms in NIST SP 800-208.[<a id="x1-2002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@20220919:800-208" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1</a>, § 4.1] Using the demo application that is available with the
reference from     <a class="url" href="https://github.com/cisco/hash-sigs" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://github.com/cisco/hash-sigs</span></a>, an application/firmware hashing mechanism can be
implemented:
</p>
   

<!-- l. 33 -->


<p id="-lms-signature-of-myappexe" style="margin-bottom: 0; margin-top: 1em;"><a id="x1-2003r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>
<a id="x1-2004" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>   
</p>
<pre class="lstlisting" id="listing-1" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-2005r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>1</span><span style="color:#000000"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">$</span></span><span style="color:#000000"> <span class="ec-lmtt-10" style="font-family: monospace,monospace;">./demo </span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">genkey </span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">mykey </span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">10/8,5/1</span></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-2006r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>2</span><span style="color:#000000"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">$</span></span><span style="color:#000000"> <span class="ec-lmtt-10" style="font-family: monospace,monospace;">./demo </span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">sign </span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">mykey </span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">myapp.exe</span></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> </span><br/> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-2007r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>3</span><span style="color:#000000"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">$</span></span><span style="color:#000000"> <span class="ec-lmtt-10" style="font-family: monospace,monospace;">./demo </span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">verify </span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">mykey </span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">myapp.exe</span></span></pre>


<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 1: </span><span class="content">LMS Signature of myapp.exe</span></figcaption>
<!-- tex4ht:label?: x1-2007r1  -->


<!-- l. 39 -->
<p class="indent" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   Line 1 will generate a <span class="ec-lmtt-10" style="font-family: monospace,monospace;">mykey.prv </span>and a <span class="ec-lmtt-10" style="font-family: monospace,monospace;">mykey.pub </span>file using 2 levels of Merkle trees. The first level has a height
of 10 and Winternitz parameter of 8, and the second level a height of 5 and Winternitz parameter of 1. The NIST
800-208 standard permits Merkle tree heights of 5, 10, 15, 20, or 25, and RFC 8554 specifies that the Winternitz
parameter may be 1, 2, 4, or 8. There are limits to the number of signatures an LMS key can be used
for, and higher Merkle tree heights can take a long time to generate a key (it took nearly 2 hours
for me to generate a key with <i>h</i> = 25). At <i>h</i> = 5, the key is only good for a handful of signatures.
Generally speaking, larger Merkle tree heights take longer to generate but can be safely used for more
signatures. Higher Winternitz parameters minimize the signature size while increasing the time. RFC
8554 documents that a single Merkle tree level generated with <span class="ec-lmtt-10" style="font-family: monospace,monospace;">15/8 </span>will be good for about 30,000
signatures, while a 2-level Merkle tree generated with <span class="ec-lmtt-10" style="font-family: monospace,monospace;">25/8,15/8 </span>would be good for more than 1 trillion
signatures.
</p>
<!-- l. 41 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Line 2 signs a file (in this case, an executable) using <span class="ec-lmtt-10" style="font-family: monospace,monospace;">mykey.prv</span>. This generates a <span class="ec-lmtt-10" style="font-family: monospace,monospace;">myapp.exe.sig </span>file with
the signature. An additional note of caution should be made: each signature advances the private
key. <span class="ec-lmtt-10" style="font-family: monospace,monospace;">mykey.prv </span>changes after every valid signature. If signatures are generated using the same key
information more than once, the security of those hashes may leak information about the private key.
Backing up the private key is not sufficient: a backup solution must back up the key <i>with the number of
signatures that have been made using it</i>, and a restoration process must advance the key by that many
signatures.
</p>
<!-- l. 43 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Line 3 only needs to have <span class="ec-lmtt-10" style="font-family: monospace,monospace;">mykey.pub </span>present to verify the signature on another machine.
</p>
   

<h4 class="subsectionHead" id="symmetric-key-algorithms"><span class="titlemark">1.2   </span> <a id="x1-30001.2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Symmetric Key Algorithms</h4>


<!-- l. 48 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">No change is made between CNSA 1.0 and CNSA 2.0 for symmetric block ciphers. AES with 256-bit keys is the only
algorithm permitted.
</p>
   

<div class="table" style="margin-top: 1em;">
                                                                                         
                                                                                         
<!-- l. 51 --><p class="indent" id="-symmetric-block-ciphers-cnsa-vs-" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   <a id="x1-30012" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p><figure class="float" style="margin-left: auto; margin-right: auto;">
                                                                                         
                                                                                         
<div class="tabular" style="text-align: center; margin-top: 0.5em; margin-bottom: 0.5em;"> <table class="tabular" id="TBL-3" style="border-collapse: collapse; border-spacing: 0; margin-left: auto; margin-right: auto;"><colgroup id="TBL-3-1g"><col id="TBL-3-1" style="border-left: 1px solid black; border-right: 1px solid black;"/></colgroup><colgroup id="TBL-3-2g"><col id="TBL-3-2" style="border-right: 1px solid black;"/></colgroup><tr class="hline" style="border-top: 1px solid black;"><td style="padding: 0;"/><td style="padding: 0;"/></tr><tr id="TBL-3-1-" style="vertical-align:baseline;"><td class="td11" id="TBL-3-1-1" style="padding-left: 5pt; padding-right: 5pt; white-space: normal; text-align: left;" align="left"><!-- l. 53 --><p class="noindent" style="margin-bottom: 0em; margin-top: 0em;"><strong>CNSA 1.0</strong>                                                </p></td>
                                               <td class="td11" id="TBL-3-1-2" style="padding-left: 5pt; padding-right: 5pt; white-space: normal; text-align: left;" align="left"><!-- l. 53 --><p class="noindent" style="margin-bottom: 0em; margin-top: 0em;"><strong>CNSA 2.0</strong>                                                </p></td></tr><tr class="hline" style="border-top: 1px solid black;"><td style="padding: 0;"/><td style="padding: 0;"/></tr><tr id="TBL-3-2-" style="vertical-align:baseline;"><td class="td 11" id="TBL-3-2-1" style="white-space:normal; text-align:left;"><!-- l. 55 --><p class="noindent" style="margin-bottom: 0em; margin-top: 0em;">Advanced Encryption Standard (AES) using 256-bit
keys                                                                  </p></td><td class="td11" id="TBL-3-2-2" style="padding-left: 5pt; padding-right: 5pt; white-space: normal; text-align: left;" align="left"><!-- l. 55 --><p class="noindent" style="margin-bottom: 0em; margin-top: 0em;">Advanced Encryption Standard (AES) using 256-bit
keys                                                                 </p></td>
</tr><tr class="hline" style="border-top: 1px solid black;"><td style="padding: 0;"/><td style="padding: 0;"/></tr></table></div>
<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Table 2: </span><span class="content">Symmetric Block Ciphers: CNSA 1.0 vs 2.0</span></figcaption><!-- tex4ht:label?: x1-30012  -->
                                                                                         
                                                                                         
   
</figure>
</div>
   

<h4 class="subsectionHead" id="hashing"><span class="titlemark">1.3   </span> <a id="x1-40001.3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Hashing</h4>


<!-- l. 63 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">CNSA 2.0 officially adds SHA-512 as an approved hash, but continues to permit SHA-384 as an approved hashing
algorithm. </p>
<div class="table" style="margin-top: 1em;">
                                                                                         
                                                                                         
<!-- l. 65 --><p class="indent" id="-hashing-cnsa-vs-" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   <a id="x1-40013" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p><figure class="float" style="margin-left: auto; margin-right: auto;">
                                                                                         
                                                                                         
<div class="tabular" style="text-align: center; margin-top: 0.5em; margin-bottom: 0.5em;"> <table class="tabular" id="TBL-4" style="border-collapse: collapse; border-spacing: 0; margin-left: auto; margin-right: auto;"><colgroup id="TBL-4-1g"><col id="TBL-4-1" style="border-left: 1px solid black; border-right: 1px solid black;"/></colgroup><colgroup id="TBL-4-2g"><col id="TBL-4-2" style="border-right: 1px solid black;"/></colgroup><tr class="hline" style="border-top: 1px solid black;"><td style="padding: 0;"/><td style="padding: 0;"/></tr><tr id="TBL-4-1-" style="vertical-align:baseline;"><td class="td11" id="TBL-4-1-1" style="padding-left: 5pt; padding-right: 5pt; white-space: normal; text-align: left;" align="left"><!-- l. 67 --><p class="noindent" style="margin-bottom: 0em; margin-top: 0em;"><strong>CNSA 1.0</strong>                                                </p></td>
                                               <td class="td11" id="TBL-4-1-2" style="padding-left: 5pt; padding-right: 5pt; white-space: normal; text-align: left;" align="left"><!-- l. 67 --><p class="noindent" style="margin-bottom: 0em; margin-top: 0em;"><strong>CNSA 2.0</strong>                                                </p></td></tr><tr class="hline" style="border-top: 1px solid black;"><td style="padding: 0;"/><td style="padding: 0;"/></tr><tr id="TBL-4-2-" style="vertical-align:baseline;"><td class="td 11" id="TBL-4-2-1" style="white-space:normal; text-align:left;"><!-- l. 69 --><p class="noindent" style="margin-bottom: 0em; margin-top: 0em;">Secure Hash Algorithm 2 (SHA-2) with 384-bit digests
(SHA-384)                                                         </p></td><td class="td11" id="TBL-4-2-2" style="padding-left: 5pt; padding-right: 5pt; white-space: normal; text-align: left;" align="left"><!-- l. 69 --><p class="noindent" style="margin-bottom: 0em; margin-top: 0em;">Secure  Hash  Algorithm  2  (SHA-2)  with  384-bit  or
512-bit digests (SHA-384 or SHA-512)                    </p></td>
</tr><tr class="hline" style="border-top: 1px solid black;"><td style="padding: 0;"/><td style="padding: 0;"/></tr></table></div>
<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Table 3: </span><span class="content">Hashing: CNSA 1.0 vs 2.0</span></figcaption><!-- tex4ht:label?: x1-40013  -->
                                                                                         
                                                                                         
   
</figure>
</div>


<!-- l. 75 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Some may notice that internal hashes in the software and firmware signing algorithms use smaller hash sizes or
different hashing algorithms. For example, LMS permits the use of SHAKE-256, one of the unapproved SHA-3
algorithms from FIPS 202, internally. “NSA has no concerns about this, but does not anticipate approving SHA-3
algorithms for general-purpose use at this time.”[<a id="x1-4002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@20220919:cnsafaq" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">4</a>]
</p>
   

<h4 class="subsectionHead" id="asymmetric-digital-signatures-and-key-establishment"><span class="titlemark">1.4   </span> <a id="x1-50001.4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Asymmetric Digital Signatures and Key Establishment</h4>


<!-- l. 79 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">CNSA 2.0 deprecates all of the algorithms of CNSA 1.0, requiring the use of the CRYSTALS-Dilithium algorithm.
</p>
<div class="table" style="margin-top: 1em;">
                                                                                         
                                                                                         
<!-- l. 81 --><p class="indent" id="-asymmetric-digital-signature-and-key-establishment-cnsa-vs-" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   <a id="x1-50014" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p><figure class="float" style="margin-left: auto; margin-right: auto;">
                                                                                         
                                                                                         
<div class="tabular" style="text-align: center; margin-top: 0.5em; margin-bottom: 0.5em;"> <table class="tabular" id="TBL-5" style="border-collapse: collapse; border-spacing: 0; margin-left: auto; margin-right: auto;"><colgroup id="TBL-5-1g"><col id="TBL-5-1" style="border-left: 1px solid black; border-right: 1px solid black;"/></colgroup><colgroup id="TBL-5-2g"><col id="TBL-5-2" style="border-right: 1px solid black;"/></colgroup><tr class="hline" style="border-top: 1px solid black;"><td style="padding: 0;"/><td style="padding: 0;"/></tr><tr id="TBL-5-1-" style="vertical-align:baseline;"><td class="td11" id="TBL-5-1-1" style="padding-left: 5pt; padding-right: 5pt; white-space: normal; text-align: left;" align="left"><!-- l. 83 --><p class="noindent" style="margin-bottom: 0em; margin-top: 0em;"><strong>CNSA 1.0</strong>                                                </p></td>
                                               <td class="td11" id="TBL-5-1-2" style="padding-left: 5pt; padding-right: 5pt; white-space: normal; text-align: left;" align="left"><!-- l. 83 --><p class="noindent" style="margin-bottom: 0em; margin-top: 0em;"><strong>CNSA 2.0</strong>                                                </p></td></tr><tr class="hline" style="border-top: 1px solid black;"><td style="padding: 0;"/><td style="padding: 0;"/></tr><tr id="TBL-5-2-" style="vertical-align:baseline;"><td class="td 11" id="TBL-5-2-1" style="white-space:normal; text-align:left;"><!-- l. 85 --><p class="noindent" style="margin-bottom: 0em; margin-top: 0em;">Rivest-Shamir-Adleman    (RSA)    with    minimum
3072-bit modulus<br class="newline"/>Elliptic Curve Digital Signature Algorithm (ECDSA)
using curve P-384<br class="newline"/>Diffie-Hellman  (DH)  Key  Exchange  with  minimum
3072-bit modulus<br class="newline"/>Elliptic Curve Diffie-Hellman (ECDH) Key Exchange
using curve P-384                                                </p></td>
                                               <td class="td11" id="TBL-5-2-2" style="padding-left: 5pt; padding-right: 5pt; white-space: normal; text-align: left;" align="left"><!-- l. 85 --><p class="noindent" style="margin-bottom: 0em; margin-top: 0em;">CRYSTALS-Kyber at Level V<br class="newline"/>CRYSTALS-Dilithium at Level V                          </p></td>
</tr><tr class="hline" style="border-top: 1px solid black;"><td style="padding: 0;"/><td style="padding: 0;"/></tr></table></div>
<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Table 4: </span><span class="content">Asymmetric Digital Signature and Key Establishment: CNSA 1.0 vs 2.0</span></figcaption><!-- tex4ht:label?: x1-50014  -->
                                                                                         
                                                                                         
   
</figure>
</div>


<!-- l. 91 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   To achieve NIST Level V functionality for the CRYSTALS-Kyber algorithm, the CRYSTALS-Kyber parameters
must be set to use K<span class="small-caps" style="font-variant: small-caps;">yber</span>1024 or K<span class="small-caps" style="font-variant: small-caps;">yber</span>1024-90s. While both parameter sets are permitted by CNSA 2.0,
K<span class="small-caps" style="font-variant: small-caps;">yber</span>1024 uses SHAKE and SHA-3 internally, both of which, on their own, are unapproved algorithms. Instead,
K<span class="small-caps" style="font-variant: small-caps;">yber</span>1024-90s uses AES-256-CTR and SHA-2 internally, using SHAKE-256 only for the Extendable-Output
Function (XOF).
</p>
<!-- l. 93 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Amazon Web Services (AWS) and the Open Quantum Safe (OQS) project implement CRYSTALS. While
production implementations are not recommended yet, configuring the OQS port of OpenSSL so that it uses
CRYSTALS-Kyber can be done with the command in Listing <a href="#x1-5002r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2<!-- tex4ht:ref: lst:20220919:kyber  --></a>. This will configure OpenSSL to use the CNSA 2.0
implementations of K<span class="small-caps" style="font-variant: small-caps;">yber</span>1024.
</p>
   

<!-- l. 95 -->


<p id="-configuring-openssl-tls-for-using-crystalskyber" style="margin-bottom: 0; margin-top: 1em;"><a id="x1-5002r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>
<a id="x1-5003" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>   
</p>
<pre class="lstlisting" id="listing-2" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-5004r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">$</span></span><span style="color:#000000"> <span class="ec-lmtt-10" style="font-family: monospace,monospace;">./Configure </span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">-DOQS_DEFAULT_GROUPS="kyber1024,p521_kyber1024,kyber90s1024,p521_kyber90s1024"</span></span></pre>


<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 2: </span><span class="content">Configuring OpenSSL TLS 1.3 for using CRYSTALS-Kyber</span></figcaption>
<!-- tex4ht:label?: x1-5004r1  -->


<!-- l. 99 -->
<p class="indent" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   You may notice that the implementation in OQS OpenSSL includes key exchange using ECDH with the P-521
curve, a curve not permitted under CNSA 1.0 and 2.0. There is not yet a reference implementation for OQS
using CRYSTALS-Dilithium; however, we should see updates to the standard to implement this soon.
Currently, only the Dilthium5 parameter sets achieve NIST Level V functionality. Currently, both
Dilithium5 and Dilithium5-AES (where AES-256-CTR and SHA-2 are used instead of SHAKE-256)
achieve the CNSA 2.0 parameter goals. This creates a public key of 2592-bytes and a secret key of
4864-bytes.
</p>
<!-- l. 101 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   During the CNSA 1.0 to 2.0 transition, there will likely be several years where both implementations continue to
exist. During this time period, expect to see several hybrid implementations (such as K<span class="small-caps" style="font-variant: small-caps;">yber</span>’s “90s” parameter sets
and Dilthium’s AES algorithm options. These will likely begin to fade out of use as the 1.0 suite continues its slow
march to obsolescence.
</p>
   

<h4 class="subsectionHead" id="conclusion"><span class="titlemark">1.5   </span> <a id="x1-60001.5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Conclusion</h4>


<!-- l. 104 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">We are likely more than a decade away from seeing CNSA-2.0-only implementations; however, for project
acquisitions and contract writers, it may be necessary to plan for these architecture changes before the next contract
awards. The CNSA 2.0 implementation timeline indicates that the hybrid approaches will start rolling out
in the 2025 timeframe with preference given to the 2.0 algorithms over the 1.0 algorithms by 2030.
Finally, we should see the obsolescence of 1.0 as it is replaced with 2.0-only implementations in the
2033-2035 timeframe. As with most government mandates, expect delays, but prepare for the best. We’ll
know if the timeline is on-track if the final CRYSTALS parameter sets are published by the end of
2024.
                                                                                         
                                                                                         
</p>
   

<h3 class="sectionHead" id="references"><a id="x1-70001.5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>References</h3>


<!-- l. 49 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">    
</p>


<dl class="thebibliography"><dt class="thebibliography" id="X0-20220919:800-208" style="float: left; clear: left; margin-right: 1em;">
[1]  
</dt><dd class="thebibliography" id="bib-1" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20220919:800-208" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>David Cooper et al. Recommendation for Stateful Hash-Based Signature Schemes. Tech. rep. Special
Publication                             (SP)                             800-208.                             Washington,
D.C.: National Institute of Standards and Technology, 2020. <span class="small-caps" style="font-variant: small-caps;">doi</span>: <a href="https://doi.org/10.6028/NIST.SP.800-208" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">10.6028/NIST.SP.800-208</span></a>. <span class="small-caps" style="font-variant: small-caps;">url</span>:
<a class="url" href="https://nvlpubs.nist.gov/nistpubs/SpecialPublications/NIST.SP.800-208.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://nvlpubs.nist.gov/nistpubs/SpecialPublications/NIST.SP.800-208.pdf</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-swatips" style="float: left; clear: left; margin-right: 1em;">
[2]  
</dt><dd class="thebibliography" id="bib-2" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon Hood, ed. SwATips.     <a class="url" href="https://www.SwATips.com/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.SwATips.com/</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-20220919:cnsa" style="float: left; clear: left; margin-right: 1em;">
[3]  
</dt><dd class="thebibliography" id="bib-3" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20220919:cnsa" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>National
Security Agency. “Announcing the Commercial National Security Algorithm Suite 2.0”. In: (2022). <span class="small-caps" style="font-variant: small-caps;">url</span>:
<a class="url" href="https://media.defense.gov/2022/Sep/07/2003071834/-1/-1/0/CSA_CNSA_2.0_ALGORITHMS_.PDF" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://media.defense.gov/2022/Sep/07/2003071834/-1/-1/0/CSA_CNSA_2.0_ALGORITHMS_.PDF</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-20220919:cnsafaq" style="float: left; clear: left; margin-right: 1em;">
[4]  
</dt><dd class="thebibliography" id="bib-4" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20220919:cnsafaq" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>National                                                   Security                                                   Agency.
“The Commercial National Security Algorithm Suite 2.0 and Quantum Computing FAQ”. In: (2022).
<span class="small-caps" style="font-variant: small-caps;">url</span>:     <a class="url" href="https://media.defense.gov/2022/Sep/07/2003071836/-1/-1/0/CSI_CNSA_2.0_FAQ_.PDF" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://media.defense.gov/2022/Sep/07/2003071836/-1/-1/0/CSI_CNSA_2.0_FAQ_.PDF</span></a>.</p></dd></dl>

 

]]></description>
	</item>
	<item>
		<title>Don't Limit your CWEs</title>
		<link>https://www.SwATips.com/articles/20220613.html</link>
		<pubDate>Mon, 13 Jun 2022 00:00:00 -0500</pubDate>
<description><![CDATA[

<p style="margin-top: 0; margin-bottom: 0;"><a href="/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/swatips.svg" width="120" alt="SwATips" style="border-top: 0; border-left: 0; border-right: 0;"/></a>| <a href="articles/20220613.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">pdf</a> | <a rel="license" href="http://creativecommons.org/licenses/by/4.0/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/by.svg" width="60" height="21" alt="CC-BY" style="border-top: 0; border-left: 0; border-right: 0;"/></a></p>


<div class="maketitle" style="margin-top: 1em; text-align: center; margin-bottom: 2em;">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead" style="text-align: center;"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a id="x1-3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">4</a>]<br/>
</h2>
<div class="author" style="text-align: center;"><span class="ec-lmr-12" style="font-size: 120%;">Jon Hood</span></div><br/>
<div class="date" style="text-align: center;"><span class="ec-lmr-12" style="font-size: 120%;">Monday 13</span><sup class="textsuperscript"><span class="ec-lmr-9" style="font-size: 90%;">th</span></sup><span class="ec-lmr-12" style="font-size: 120%;"> June, 2022</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead" id="dont-limit-your-cwes"><span class="titlemark">1   </span> <a id="x1-10001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Don’t Limit your CWEs</h3>


<!-- l. 44 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;"><span class="ec-lmr-8" style="font-size: 80%;">Updated Friday 10</span><sup class="textsuperscript"><span class="ec-lmr-9" style="font-size: 90%;">th</span></sup><span class="ec-lmr-8" style="font-size: 80%;"> June, 2022</span>
</p>
<!-- l. 1 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   One of the trends becoming popular in recent DoD contracts is a requirement for Prime contractors to scan for
and fix a subset of Common Weakness Enumerations (CWEs) based on a list of what the government deems to be
the most relevant to the system. Much of the language is derived from sample contract language provided by the
DoD. Some sample language includes:
</p>
     

<blockquote class="quote">
<!-- l. 3 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;">The Government will provide to the Prime contractor a list of the Top-n most important CWEs.
All software delivered by the Prime contractor shall be free of all of the CWEs in the Government’s
Top-<i>n</i> CWE list. If a CWE in the Government’s Top-<i>n</i> CWE list is found to be present in the
delivered software, the Prime contractor shall be liable only to repair the defect within XX-days
at the contractor’s expense.[<a id="x1-1001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@20220613:marien" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">5</a>]</p></blockquote>


<!-- l. 6 -->
<p class="indent" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   Including language such as this in contracts creates difficulties that the acquisition team should be aware of.
Those difficulties include:
</p>
     

<ol class="enumerate1" style="list-style-type: decimal;">
<li class="enumerate" id="x1-1003x1">the possibility of a manipulative Prime developer or acquisition customer
</li>
<li class="enumerate" id="x1-1005x2">the lack of prioritizing potentially critical CWEs
</li>
<li class="enumerate" id="x1-1007x3">a moving-target metric that changes often</li></ol>


<!-- l. 13 -->
<p class="indent" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   Today’s Software Assurance Tip will attempt to draw attention to these pitfalls in an effort to help acquisition
teams be aware of behaviors and metrics that may introduce unintended security errors for a program’s software
assurance process.
</p>
<!-- l. 15 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead" id="manipulative-primes-and-customers"><span class="titlemark">1.1   </span> <a id="x1-20001.1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Manipulative Primes and Customers</h4>


<!-- l. 16 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Prime development teams involved in acquisition contracts often have the difficult task of balancing the desire to
make their company profitable with the security of the customer they are supporting. No matter how
much a company spends on security and safety, there is always something else they can be doing to
improve their security stance. It’s why RMF controls and cybersecurity are built into the acquisition
process: the customer must define “how much is enough” security to have confidence in the delivered
system.
</p>
<!-- l. 18 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   The Top-<i>n</i> language[<a href="#cite.0@20220613:marien" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">5</a>] is one such “how much is enough” limiter intended to give the customer reasonable levels
of assurance while limiting the liability of the Prime contractor from having to do an overly burdensome number of
security verifications.
</p>
<!-- l. 20 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   This creates a potential situation of abuse if relationships between the Prime and the Customer become strained.
Since the CWEs are a hierarchy in addition to being a list, it becomes trivial to hide a buffer overflow from having
to be addressed. Consider the Top 25 CWEs for 2021.[<a id="x1-2001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@20220613:2021Dangerous" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1</a>] While operating outside of the bounds of memory
(CWE-119) is 17 on the list, many tools report the issue to CWE-120 which is absent from the list. Lest the
                                                                                         
                                                                                         
acquisition team attempt to compensate for this and add CWE-120 to their top-<i>n</i> list, the Prime
can just classify them at an even lower level as stack-based or heap-based overflows (CWE-121 and
CWE-122 respectively). By the time an acquisition team traverses the CWEs to include everything that
<i>could</i> be an issue, their top-<i>n</i> list becomes nothing less than the entirety of the already existing CWE
hierarchy.
</p>
<!-- l. 22 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   If the contract language settles on a fixed number for <i>n</i>, the acquisition customer can create a
dynamically changing list of CWEs that must be addressed. After all, as new CWEs and classes of
weaknesses are released and included in the CWEs, shouldn’t a program’s software assurance process adapt
to changing threats? In 2017, homoglyphs were introduced to the CWE list, and we have observed
how they can absolutely cripple a weapons system.[<a id="x1-2002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@20220613:hood" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2</a>, <a id="x1-2003" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@20220613:hood2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">3</a>] Nevertheless, I’ve never seen CWE-1007 on
any top-<i>n</i> list! Suppose the threat landscape changes such that homographic representation issues
become important. The program should absolutely have the power to include it in their list of important
CWEs.
</p>
<!-- l. 24 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Overzealous acquisition Customers and manipulative Prime developers pose a serious and meaningful threat to
this type of contract language.
</p>
<!-- l. 26 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead" id="forgotten-cwes"><span class="titlemark">1.2   </span> <a id="x1-30001.2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Forgotten CWEs</h4>


<!-- l. 27 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">In addition to the CWE-1007 example above, another important example that we have run into frequently is the
presence of CWE-917, Expression Language Injection, which made its debut on the 2021 Top 25 list by being listed
in the <i>Weaknesses on the Cusp</i> list as #30.[<a id="x1-3001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@20220613:2021Dangerous" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1</a>] Since 2016, our software assurance team has identified this as one of
the most dangerous weaknesses we run into, and the National Vulnerability Database agrees with an average CVSS
score of 9.05: higher than any other CWE on the list.
</p>
<!-- l. 29 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   A contract which implements a CWE limit must balance the <strong>prevalence</strong> of an issue with the <strong>security impact</strong>
of the risk it presents. What’s more dangerous for the program: ignoring 1000 resource leaks that may exist in the
software or the 1 location where an attacker controls the input into a regular expression match? That answer may
differ amongst varying systems.
</p>
<!-- l. 31 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead" id="a-moving-target"><span class="titlemark">1.3   </span> <a id="x1-40001.3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>A Moving Target</h4>


<!-- l. 32 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Because of the changing system and threat landscapes, a top-<i>n</i> list is unreasonable to define statically in
the contract language. And because of a Prime’s need to control costs, it is unreasonable to define it
dynamically. This gets into the key recommendation of today’s tip: for a program that feels it necessary to
define a top-<i>n</i> list contractually, there should also be language to keep it updated at least annually to
address the changing security concerns of the program. My recommendation is to add language like the
following:
</p>
     

<blockquote class="quote">
<ul class="itemize1">    
<li class="itemize">The Top-<i>n</i> list may be changed at most yearly by the acquisition team.
</li>
<li class="itemize">Each reported CWE must also be reported as findings against its hierarchy of CWEs as
defined by the Research Concepts view (CWE-1000).</li></ul>
</blockquote>

                                                                                         
                                                                                         


<!-- l. 39 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Placing a limit on how often the Top-<i>n</i> list can change prevents an abusive acquisition team that creates a constantly
moving target that the Prime can never hit while still permitting reasonable updates to the security posture of the
system. Requiring Prime teams to report the hierarchy of their findings prevents an issue with them hiding behind
more esoteric CWEs.
                                                                                         
                                                                                         
</p>
   

<h3 class="sectionHead" id="references"><a id="x1-50001.3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>References</h3>


<!-- l. 49 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">    
</p>


<dl class="thebibliography"><dt class="thebibliography" id="X0-20220613:2021Dangerous" style="float: left; clear: left; margin-right: 1em;">
[1]  
</dt><dd class="thebibliography" id="bib-1" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20220613:2021Dangerous" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>CWE Content Team. “2021 CWE Top 25 Most Dangerous Software Weaknesses”. In: (2021). <span class="small-caps" style="font-variant: small-caps;">url</span>:
<a class="url" href="https://cwe.mitre.org/top25/archive/2021/2021_cwe_top25.html" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://cwe.mitre.org/top25/archive/2021/2021_cwe_top25.html</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-20220613:hood" style="float: left; clear: left; margin-right: 1em;">
[2]  
</dt><dd class="thebibliography" id="bib-2" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20220613:hood" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon    Hood.    “Homoglyphs    and    Homographic    Attacks”.    In:    SwATips.com    (2021).    <span class="small-caps" style="font-variant: small-caps;">url</span>:
<a class="url" href="https://www.swatips.com/articles/20210510.html" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.swatips.com/articles/20210510.html</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-20220613:hood2" style="float: left; clear: left; margin-right: 1em;">
[3]  
</dt><dd class="thebibliography" id="bib-3" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20220613:hood2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon    Hood.    “Malicious    Injection    of    Source    Code”.    In:    SwATips.com    (2021).    <span class="small-caps" style="font-variant: small-caps;">url</span>:
<a class="url" href="https://www.swatips.com/articles/20211129.html" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.swatips.com/articles/20211129.html</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-swatips" style="float: left; clear: left; margin-right: 1em;">
[4]  
</dt><dd class="thebibliography" id="bib-4" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon Hood, ed. SwATips.     <a class="url" href="https://www.SwATips.com/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.SwATips.com/</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-20220613:marien" style="float: left; clear: left; margin-right: 1em;">
[5]  
</dt><dd class="thebibliography" id="bib-5" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20220613:marien" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>John R. Marien and Robert A. Martin. Incorporating Software Assurance into Department of Defense Acquisition Contracts.
Washington, D.C., 2017. <span class="small-caps" style="font-variant: small-caps;">url</span>:   <a class="url" href="https://rt.cto.mil/wp-content/uploads/2019/06/Incorporating-SwA-Contracts-2017-11-15.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://rt.cto.mil/wp-content/uploads/2019/06/Incorporating-SwA-Contracts-2017-11-15.pdf</span></a>.</p></dd></dl>

 

]]></description>
	</item>
