	<item>
		<title>Unsafe at Any Speed: The Designed-In Dangers of DevSecOps</title>
		<link>https://www.SwATips.com/articles/20260126.html</link>
		<pubDate>Mon, 26 Jan 2026 00:00:00 -0600</pubDate>
<description><![CDATA[

<p style="margin-top: 0; margin-bottom: 0;"><a href="/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/swatips.svg" width="120" alt="SwATips" style="border-top: 0; border-left: 0; border-right: 0;"/></a>| <a href="articles/20260126.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">pdf</a> | <a rel="license" href="http://creativecommons.org/licenses/by/4.0/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/by.svg" width="60" height="21" alt="CC-BY" style="border-top: 0; border-left: 0; border-right: 0;"/></a></p>


<div class="maketitle" style="margin-top: 1em; text-align: center; margin-bottom: 2em;">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead" style="line-height: 1.2; text-align: center;"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a id="x1-3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0_swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">5</a>]<br/>
</h2>
 <div class="author" style="text-align: center;"><span class="ec-lmr-12" style="font-size: 120%;">Jon Hood</span></div><br/>
<div class="date" style="text-align: center;"><span class="ec-lmr-12" style="font-size: 120%;">Monday 26</span><sup class="textsuperscript"><span class="ec-lmr-9" style="font-size: 90%;">th</span></sup><span class="ec-lmr-12" style="font-size: 120%;"> January, 2026</span></div>
</div>

                                                                                         
                                                                                         
   


<h3 class="sectionHead" id="unsafe-at-any-speed-the-designedin-dangers-of-devsecops" style="line-height: 1.2; font-size: 1.5157em;"><span class="titlemark">1   </span> <a id="x1-10001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Unsafe at Any Speed: The Designed-In Dangers of DevSecOps</h3>


<!-- l. 47 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;"><span class="ec-lmr-8" style="font-size: 80%;">Updated Tuesday 27</span><sup class="textsuperscript"><span class="ec-lmr-9" style="font-size: 90%;">th</span></sup><span class="ec-lmr-8" style="font-size: 80%;"> January, 2026</span>

</p>
   

<h4 class="subsectionHead" id="introduction" style="line-height: 1.2; font-size: 1.3195em;"><span class="titlemark">1.1   </span> <a id="x1-20001.1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Introduction</h4>


<!-- l. 3 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">In 1965, Ralph Nader published his book, <i>Unsafe at Any Speed: The Designed-In Dangers of the American
Automobile.</i> In it, one of his critiques included the ignorance of “Crashworthiness” standards, claiming that vehicle
manufacturers knew about the secondary crash events (riders hitting the internal parts of a vehicle and suffering
injury) but chose to save cost and do nothing about it.
</p>
<!-- l. 5 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Sixty years later, we have an administration pushing forward sound standards that are actively being ignored
and redefined. In this week’s SwATip, we’ll take a look at the Department of War’s latest software
development memorandums and guidelines, then get a boots-on-the-ground look at how they’re being
redefined.

</p>
   

<h4 class="likesubsectionHead" id="lethal-speed" style="line-height: 1.2; font-size: 1.3195em;"><a id="x1-3000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Lethal Speed</h4>


<!-- l. 8 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">In March 2025, Secretary Hegseth published a memo directing the Department of Defense to adopt the Software
Acquisition Pathway (SWP), DoDI 5000.87, as the means of acquiring, developing, and iterating updates for
software.[<a id="x1-3001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0_20260126_lethal" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2</a>]

</p>


<!-- l. 10 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;"><span class="paragraphHead" id="the-false-claim" style="margin-top: 2em; font-weight: bold;"><a id="x1-4000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><span class="ec-lmbx-10" style="font-weight: bold;">The false claim</span></span>
is that the DoD/DoW is focusing on fielding quickly in favor of lethality rather than bureaucratic
processes like software assurance, validation, and accreditation. Software development organizations are
pointing to this memo as justification for completely skipping the processes that make code delivery
secure.

</p>


<!-- l. 12 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;"><span class="paragraphHead" id="reality" style="margin-top: 2em; font-weight: bold;"><a id="x1-5000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><span class="ec-lmbx-10" style="font-weight: bold;">Reality</span></span>
is the exact opposite. Instead, SWP pushes the old DoD way of doing things into the modern era. “Cybersecurity
and program protection will be addressed from program inception throughout the program’s lifecycle…” Instead of a
point-in-time inspection and waterfall-like process of evaluating software after it’s written, cybersecurity policies
related to software must perform the cybersecurity validation as part of the development process, earlier in the
lifecycle when it will not slow down deployment. “Software assurance, cyber security, test and evaluation are integral
parts of this approach to continually assess and measure cybersecurity preparedness and responsiveness,
identify and address risks and execute mitigation actions.”[<a id="x1-5001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0_20260126_dodi500087" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1</a>] Leadership is forcing something that
we’ve seen for decades: the need to bring cybersecurity assessment into the development pipelines
early.[<a id="x1-5002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0_20260126_hood" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">4</a>]
</p>
<!-- l. 14 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   The DoW isn’t saying to just ignore the processes that identify risks. Yes, the need to field and achieve lethality
may be greater than the risk of fielding, but that risk should still be enumerated and identified as early in the
process as possible.

                                                                                         
                                                                                         
</p>
   

<h4 class="likesubsectionHead" id="rmf-is-dead" style="line-height: 1.2; font-size: 1.3195em;"><a id="x1-6000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>RMF Is Dead</h4>


<!-- l. 17 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">In September 2025, the DoW announced the move to the Cybersecurity Risk Management Construct
(CSRMC). The Risk Management Framework’s (RMF) documentation-heavy approach relied on static
point-in-time inspections and checklists, a concept already denounced in the aforementioned Hegseth
memo.

</p>


<!-- l. 19 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;"><span class="paragraphHead" id="the-partially-false-claim" style="margin-top: 2em; font-weight: bold;"><a id="x1-7000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><span class="ec-lmbx-10" style="font-weight: bold;">The partially false claim</span></span>
is that RMF is dead; therefore, its cybersecurity requirements are no longer valid.

</p>


<!-- l. 21 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;"><span class="paragraphHead" id="reality1" style="margin-top: 2em; font-weight: bold;"><a id="x1-8000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><span class="ec-lmbx-10" style="font-weight: bold;">Reality</span></span>
is that cybersecurity professionals engaged in technical activities are celebrating. CSRMC moves from these
static assessments to the continuous assessment frameworks already accounted for in the RMF continuous
monitoring construct. This frees up cybersecurity teams. Instead of point-in-time inspections, they must rely on
automated, AI-enabled tools to continuously assess networks, systems, and components. The standard is no
longer whether a cybersecurity professional can spend weeks or even months documenting their findings
and getting security managers to push their assessment results into eMASS; it’s now on their ability
to flag concerns in the automated and continuous assessment pipelines that are now required. Red
teaming, blue teaming, and pentesting are all moved into the <strong>Test</strong> portion of the CSRMC while Software
Assurance is embedded into the security requirements of the architecture in the very first <strong>Design</strong>
phase.
</p>
<!-- l. 23 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   The reports of RMF’s death are greatly exaggerated. Had your program been implementing continuous
monitoring, “RMF 2.0,” or continuous ATO guidance, it would be in shape to implement what’s coming with
CSRMC. Shifting left into automated pipelines instead of documenting findings in reports attached to eMASS
that are ignored until there’s a problem represents a proactive (rather than reactive) cybersecurity
posture.

</p>
   

<h4 class="likesubsectionHead" id="less-cybersecurity-training" style="line-height: 1.2; font-size: 1.3195em;"><a id="x1-9000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Less Cybersecurity Training</h4>


<!-- l. 26 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Also in September, Secretary Hegseth announced a reduction in mandatory annual training.[<a id="x1-9001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0_20260126_hegseth" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">6</a>] In
the memo, Secretary Hegseth instructed the CIO to relax the mandatory frequency for cybersecurity
training.[<a id="x1-9002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0_20260126_hegseth2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">3</a>]

</p>


<!-- l. 28 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;"><span class="paragraphHead" id="the-false-claim1" style="margin-top: 2em; font-weight: bold;"><a id="x1-10000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><span class="ec-lmbx-10" style="font-weight: bold;">The false claim</span></span>
is that cybersecurity training and requirements are being eliminated.

</p>


<!-- l. 30 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;"><span class="paragraphHead" id="reality2" style="margin-top: 2em; font-weight: bold;"><a id="x1-11000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><span class="ec-lmbx-10" style="font-weight: bold;">Reality</span></span>
is that consolidating and simplifying the frequency of addressing these topics helps prioritize the execution of
warfighting, strengthening lethality (tying it to the first memorandum).

                                                                                         
                                                                                         
</p>
   

<h4 class="likesubsectionHead" id="bidenera-software-assurance-is-rescinded" style="line-height: 1.2; font-size: 1.3195em;"><a id="x1-12000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Biden-Era Software Assurance Is Rescinded</h4>


<!-- l. 33 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">In January 2026, the Office of Management and Budget published a memo rescinding the Biden-era SBOM
requirements, moving the monolithic SBOM approach decisions back to the project offices to implement supply
chain security as they deem appropriate for their programs.[<a id="x1-12001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0_20260126_vought" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">7</a>]

</p>


<!-- l. 35 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;"><span class="paragraphHead" id="the-false-claim2" style="margin-top: 2em; font-weight: bold;"><a id="x1-13000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><span class="ec-lmbx-10" style="font-weight: bold;">The false claim</span></span>
has been made that broadly applies this rescission to all of Software Assurance when the focus is on dependency
lists, Bills of Material, and other supply chain security requirements.

</p>


<!-- l. 37 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;"><span class="paragraphHead" id="reality3" style="margin-top: 2em; font-weight: bold;"><a id="x1-14000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><span class="ec-lmbx-10" style="font-weight: bold;">Reality</span></span>
is that the burden of software security is not one-size-fits-all. Giving the programs back their authority to
determine software security puts risk decisions back into the management chain where it belongs. “Agencies shall
continue to maintain a complete inventory of software and hardware and develop software and hardware assurance
policies and processes that match their risk determinations and mission needs.”

</p>
   

<h4 class="likesubsectionHead" id="conclusion" style="line-height: 1.2; font-size: 1.3195em;"><a id="x1-15000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Conclusion</h4>


<!-- l. 41 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Another critique in Nader’s <i>Unsafe at Any Speed</i> is that those responsible for developing vehicles would blame “the
nut behind the wheel,” shifting safety and operation to the driver’s fault rather than building a sound vehicle that
could protect them better. Today, we are seeing outrage at sound policies that can be implemented
appropriately and safely. Nevertheless, there has been no shortage of development organizations attempting
to convince leadership to ignore cybersecurity in favor of going fast. These organizations abuse the
memorandums and standards established for them and construct a fortress around themselves to protect them
from the fallout. DevSecOps environments are created on the platforms which shift risk and blame
to external stakeholders who cannot mitigate it rather than taking the accountability demanded by
leadership.
</p>
<!-- l. 43 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Nader ended his book noting the coming struggle for safety, begging the government to step in and reform the
organizations that prioritized profits over safety. Today we stand on the edge of that happening again: can vendors
be trusted to police themselves by bringing the cybersecurity responsibilities into the development pipeline,
or will they commit the same mistakes as the auto industry of the 1960’s by relaxing cybersecurity
standards and blaming others? If you hear of a development organization pushing any of the false claims
documented here, then it may be already too late. The development organization isn’t “shifting left” and
moving cybersecurity where it is mandated to be; they’re simply doing nothing and hoping for the
best.
                                                                                         
                                                                                         
   

</p>
   

<h3 class="sectionHead" id="references" style="line-height: 1.2; font-size: 1.5157em;"><a id="x1-16000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>References</h3>


<!-- l. 52 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">    
</p>


<dl class="thebibliography"><dt class="thebibliography" id="X0-20260126_dodi500087" style="float: left; clear: left; margin-right: 1em;">
[1]  
</dt><dd class="thebibliography" id="bib-1" style="margin-left: 2.5em;">
<!-- l. 52 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0_20260126_dodi500087" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Department  of  Defense.  <span class="uline" style="text-decoration: underline;">Department  of  Defense  Instruction  5000.87.  Operation  of  the  Software
Acquisition   Pathway</span>.   Tech.   rep.   Washington,   D.C.:   Department   of   Defense,   2020.   <span class="small-caps" style="font-variant: small-caps;">url</span>:   
<a class="url" href="https://www.esd.whs.mil/Portals/54/Documents/DD/issuances/dodi/500087p.PDF" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.esd.whs.mil/Portals/54/Documents/DD/issuances/dodi/500087p.PDF</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-20260126_lethal" style="float: left; clear: left; margin-right: 1em;">
[2]  
</dt><dd class="thebibliography" id="bib-2" style="margin-left: 2.5em;">
<!-- l. 52 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0_20260126_lethal" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Peter Hegseth. <span class="uline" style="text-decoration: underline;">Directing Modern Software Acquisition to Maximize Lethality</span>. 2025. <span class="small-caps" style="font-variant: small-caps;">url</span>: <a class="url" href="https://media.defense.gov/2025/Mar/07/2003662943/-1/-1/1/DIRECTING-MODERN-SOFTWARE-ACQUISITION-TO-MAXIMIZE-LETHALITY.PDF" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://media.defense.gov/2025/Mar/07/2003662943/-1/-1/1/DIRECTING-MODERN-SOFTWARE-ACQUISITION-TO-MAXIMIZE-LETHALITY.PDF</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-20260126_hegseth2" style="float: left; clear: left; margin-right: 1em;">
[3]  
</dt><dd class="thebibliography" id="bib-3" style="margin-left: 2.5em;">
<!-- l. 52 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0_20260126_hegseth2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Peter Hegseth. <span class="uline" style="text-decoration: underline;">Reduction of Mandatory Training Requirements to Restore Mission Focus</span>. 2025. <span class="small-caps" style="font-variant: small-caps;">url</span>: 
<a class="url" href="https://media.defense.gov/2025/Sep/30/2003812317/-1/-1/1/SECRETARY-OF-WAR-ANNOUNCED-MEMORANDUMS.PDF" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://media.defense.gov/2025/Sep/30/2003812317/-1/-1/1/SECRETARY-OF-WAR-ANNOUNCED-MEMORANDUMS.PDF</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-20260126_hood" style="float: left; clear: left; margin-right: 1em;">
[4]  
</dt><dd class="thebibliography" id="bib-4" style="margin-left: 2.5em;">
<!-- l. 52 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0_20260126_hood" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon     Hood.     “Defensive     Development     Plans”.     In:     <span class="uline" style="text-decoration: underline;">SwATips.com</span>     (2025).     <span class="small-caps" style="font-variant: small-caps;">url</span>:     
<a class="url" href="https://www.swatips.com/articles/20250127.html" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.swatips.com/articles/20250127.html</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-swatips" style="float: left; clear: left; margin-right: 1em;">
[5]  
</dt><dd class="thebibliography" id="bib-5" style="margin-left: 2.5em;">
<!-- l. 52 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0_swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon Hood, ed. <span class="uline" style="text-decoration: underline;">SwATips</span>. <a class="url" href="https://www.SwATips.com/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.SwATips.com/</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-20260126_hegseth" style="float: left; clear: left; margin-right: 1em;">
[6]  
</dt><dd class="thebibliography" id="bib-6" style="margin-left: 2.5em;">
<!-- l. 52 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0_20260126_hegseth" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>U.S. Department of War. “Hegseth Announces War Department Reforms in Sweeping Speech to Top
Military Brass”. In: (Sept. 2025). <span class="small-caps" style="font-variant: small-caps;">url</span>: <a class="url" href="https://www.war.gov/News/News-Stories/Article/Article/4318394/hegseth-announces-war-department-reforms-in-sweeping-speech-to-top-military-bra/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.war.gov/News/News-Stories/Article/Article/4318394/hegseth-announces-war-department-reforms-in-sweeping-speech-to-top-military-bra/</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-20260126_vought" style="float: left; clear: left; margin-right: 1em;">
[7]  
</dt><dd class="thebibliography" id="bib-7" style="margin-left: 2.5em;">
<!-- l. 52 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0_20260126_vought" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Russell Vought. <span class="uline" style="text-decoration: underline;">Adopting a Risk-based Approach to Software and Hardware Security</span>. 2026. <span class="small-caps" style="font-variant: small-caps;">url</span>: 
<a class="url" href="https://www.whitehouse.gov/wp-content/uploads/2026/01/M-26-05-Adopting-a-Risk-based-Approach-to-Software-and-Hardware-Security.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.whitehouse.gov/wp-content/uploads/2026/01/M-26-05-Adopting-a-Risk-based-Approach-to-Software-and-Hardware-Security.pdf</span></a>.</p></dd></dl>

 

]]></description>
	</item>
	<item>
		<title>The -Wall GCC Flag and CWE-457: Why -Wall Does Not Offer Sufficient Protection Against Uninitialized Variables</title>
		<link>https://www.SwATips.com/articles/20250707.html</link>
		<pubDate>Mon, 07 Jul 2025 00:00:00 -0500</pubDate>
<description><![CDATA[

<p style="margin-top: 0; margin-bottom: 0;"><a href="/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/swatips.svg" width="120" alt="SwATips" style="border-top: 0; border-left: 0; border-right: 0;"/></a>| <a href="articles/20250707.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">pdf</a> | <a rel="license" href="http://creativecommons.org/licenses/by/4.0/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/by.svg" width="60" height="21" alt="CC-BY" style="border-top: 0; border-left: 0; border-right: 0;"/></a></p>


<div class="maketitle" style="margin-top: 1em; text-align: center; margin-bottom: 2em;">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead" style="line-height: 1.2; text-align: center;"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a id="x1-3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0_swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2</a>]<br/>
</h2>
 <div class="author" style="text-align: center;"><span class="ec-lmr-12" style="font-size: 120%;">Chris Ramsey</span></div><br/>
<div class="date" style="text-align: center;"><span class="ec-lmr-12" style="font-size: 120%;">Monday 7</span><sup class="textsuperscript"><span class="ec-lmr-9" style="font-size: 90%;">th</span></sup><span class="ec-lmr-12" style="font-size: 120%;"> July, 2025</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead" style="line-height: 1.2; font-size: 1.5157em;"><span class="titlemark">1   </span> <a id="x1-10001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>The -Wall GCC Flag and CWE-457: Why -Wall Does Not Offer Sufficient Protection Against Uninitialized
Variables</h3>


<!-- l. 47 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;"><span class="ec-lmr-8" style="font-size: 80%;">Updated Monday 14</span><sup class="textsuperscript"><span class="ec-lmr-9" style="font-size: 90%;">th</span></sup><span class="ec-lmr-8" style="font-size: 80%;"> July, 2025</span>
</p>
<!-- l. 1 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead" style="line-height: 1.2; font-size: 1.3195em;"><span class="titlemark">1.1   </span> <a id="x1-20001.1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Introduction</h4>


<!-- l. 3 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">CWE-457 is a category of software weakness related to the use of uninitialized variables.[<a id="x1-2001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0_20250707_cwe-457" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1</a>] In some programming
languages—C and C++ in particular—local (stack) variables are not automatically initialized. Instead, they contain
garbage data, consisting of leftover values from previous operations. Using uninitialized variables can easily lead to
unpredictable behavior and security vulnerabilities.
</p>
<!-- l. 7 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   The <span class="ec-lmtt-10" style="font-family: monospace,monospace;">-Wall </span>command-line argument in the GNU Compiler Collection (GCC) enables a wide range of useful
warnings, including some that help detect the use of uninitialized variables. For example, consider the program in
Listing <a href="#x1-2002r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1<!-- tex4ht:ref: lst:20250707:1  --></a>. When compiled with the GCC arguments <span class="ec-lmtt-10" style="font-family: monospace,monospace;">-Wall </span>and <span class="ec-lmtt-10" style="font-family: monospace,monospace;">-Werror</span>, the uninitialized value is properly detected
as shown in Listing <a href="#x1-2012r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2<!-- tex4ht:ref: lst:20250707:2  --></a>.
</p>
   

<!-- l. 10 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-2002r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>
<a id="x1-2003" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>   
</p>
<pre class="lstlisting" id="listing-1" style="font-family: monospace,monospace; white-space: pre-wrap; margin-top: 0.5em; margin-bottom: 0.5em; background-color: #BFBFBF;"><span class="label" style="margin-right: 0.5em;"><a id="x1-2004r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">#</span></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">include</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">&lt;cstdio&gt;</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-2005r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-2006r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">int</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">main() {</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-2007r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">int</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">x;</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-2008r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">int</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">y = x + 1; </span><span class="ec-lmtti-10x-x-90" style="font-size: 90%; font-family: monospace,monospace; font-style: italic;">// </span><span class="ts1-lmtti10-x-x-90" style="font-size: 90%;">'</span><span class="ec-lmtti-10x-x-90" style="font-size: 90%; font-family: monospace,monospace; font-style: italic;">x</span><span class="ts1-lmtti10-x-x-90" style="font-size: 90%;">' </span><span class="ec-lmtti-10x-x-90" style="font-size: 90%; font-family: monospace,monospace; font-style: italic;">is used uninitialized</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-2009r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">printf</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">(</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">"</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">%</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">d</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">\</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">n</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">"</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">,</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">y);</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-2010r7" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">return</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">0;</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-2011r8" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">}</span></span></pre>


<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 1: </span><span class="content">Simple Uninitialized Variable</span></figcaption>
<!-- tex4ht:label?: x1-2011r1.1  -->

   

<!-- l. 21 -->


<p style="margin-top: 0; margin-bottom: 0;"><a id="x1-2012r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>
<a id="x1-2013" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>   
</p>
<pre class="lstlisting" id="listing-2" style="font-family: monospace,monospace; white-space: pre-wrap; margin-top: 0.5em; margin-bottom: 0.5em; background-color: #BFBFBF;"><span class="label" style="margin-right: 0.5em;"><a id="x1-2014r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">main</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">.</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">cpp</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">:</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">In </span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">function</span> </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">‘</span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">int</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">main</span></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">’</span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">():</span></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-2015r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">main</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">.</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">cpp</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">:5:9:</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">error:</span> </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">‘’</span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">x</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">is used uninitialized [-Werror=uninitialized]</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-2016r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">    </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">5</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">|</span> </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">    </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">int</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">y = x + 1; // </span><span class="ts1-lmtt9-" style="font-size: 90%;">'</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">x</span><span class="ts1-lmtt9-" style="font-size: 90%;">' </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">is used uninitialized</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-2017r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">      </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">|</span></span><span style="color:#000000"> </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">^</span></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-2018r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">main</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">.</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">cpp</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">:4:9:</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">note:</span> </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">‘’</span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">x</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">was declared here</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-2019r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">    </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">4</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">|</span> </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">    </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">int</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">x;</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-2020r7" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">      </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">|</span></span><span style="color:#000000"> </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">^</span></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-2021r8" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">cc1plus</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">:</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">all warnings being treated as errors</span></span></pre>


<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 2: </span><span class="content">Compilation with -Wall and -Werror</span></figcaption>
<!-- tex4ht:label?: x1-2021r1.1  -->


<!-- l. 32 -->
<p class="indent" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   This has led to a common misconception: that the <span class="ec-lmtt-10" style="font-family: monospace,monospace;">-Wall </span>flag offers developers sufficient protection against
CWE-457. However, this is not the case. In this SwA tip, we explore some common situations where <span class="ec-lmtt-10" style="font-family: monospace,monospace;">-Wall </span>fails to
detect the use of uninitialized variables.
</p>
<!-- l. 34 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="likesubsectionHead" style="line-height: 1.2; font-size: 1.3195em;"><a id="x1-3000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Example 1: Conditional Assignment</h4>


<!-- l. 36 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Consider the example in Listing <a href="#x1-3001r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">3<!-- tex4ht:ref: lst:20250707:3  --></a>. Compiling this program with GCC version (Ubuntu 13.3.0-6ubuntu2 24.04)
13.3.0 using the <span class="ec-lmtt-10" style="font-family: monospace,monospace;">-Wall </span>command-line argument produces no warnings. However, running the program a few times is
usually sufficient to demonstrate the issue. Sometimes, it does not output <span class="ec-lmtt-10" style="font-family: monospace,monospace;">10 </span>(see Listing <a href="#x1-3016r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">4<!-- tex4ht:ref: lst:20250707:4  --></a>).
</p>
   

<!-- l. 38 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-3001r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>
<a id="x1-3002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>   
</p>
<pre class="lstlisting" id="listing-3" style="font-family: monospace,monospace; white-space: pre-wrap; margin-top: 0.5em; margin-bottom: 0.5em; background-color: #BFBFBF;"><span class="label" style="margin-right: 0.5em;"><a id="x1-3003r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">#</span></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">include</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">&lt;stdio.h&gt;</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3004r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">#</span></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">include</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">&lt;stdlib.h&gt;</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3005r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">#</span></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">include</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">&lt;time.h&gt;</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3006r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-3007r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">int</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">main() {</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3008r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">int</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">x;</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3009r7" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">srand</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">(</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">time</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">(</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">NULL</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">));</span></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-3010r8" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">if</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">(rand() % 2 == 0) { </span><span class="ec-lmtti-10x-x-90" style="font-size: 90%; font-family: monospace,monospace; font-style: italic;">// 50% chance of being true</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3011r9" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">               </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">x</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">= 10;</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3012r10" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">}</span></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-3013r11" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">printf</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">(</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">"</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">%</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">d</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">\</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">n</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">"</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">,</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">x);</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3014r12" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">return</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">0;</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-3015r13" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">}</span></span></pre>


<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 3: </span><span class="content">Conditionally Uninitialized Variable</span></figcaption>
<!-- tex4ht:label?: x1-3015r  -->

   

<!-- l. 54 -->

                                                                                         
                                                                                         

<p style="margin-top: 0; margin-bottom: 0;"><a id="x1-3016r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>
<a id="x1-3017" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>   
</p>
<pre class="lstlisting" id="listing-4" style="font-family: monospace,monospace; white-space: pre-wrap; margin-top: 0.5em; margin-bottom: 0.5em; background-color: #BFBFBF;"><span class="label" style="margin-right: 0.5em;"><a id="x1-3018r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">./</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">main</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">.</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">exe</span></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-3019r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">10</span></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-3020r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">./</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">main</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">.</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">exe</span></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-3021r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">10</span></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-3022r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">./</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">main</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">.</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">exe</span></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-3023r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">32765</span></span></pre>


<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 4: </span><span class="content">Execution Showing Uninitialized Variable</span></figcaption>
<!-- tex4ht:label?: x1-3023r  -->


<!-- l. 63 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">
</p>
   

<h4 class="likesubsectionHead" style="line-height: 1.2; font-size: 1.3195em;"><a id="x1-4000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Example 2: Function Scope Escape</h4>


<!-- l. 65 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Consider the example in Listing <a href="#x1-4001r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">5<!-- tex4ht:ref: lst:20250707:5  --></a>. Using the same compiler as Example 1, GCC does not detect that variable
<span class="ec-lmtt-10" style="font-family: monospace,monospace;">x </span>remains uninitialized after the call to <span class="ec-lmtt-10" style="font-family: monospace,monospace;">foo</span>. Passing a pointer to the variable is enough to fool the
compiler.
</p>
   

<!-- l. 67 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-4001r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>
<a id="x1-4002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>   
</p>
<pre class="lstlisting" id="listing-5" style="font-family: monospace,monospace; white-space: pre-wrap; margin-top: 0.5em; margin-bottom: 0.5em; background-color: #BFBFBF;"><span class="label" style="margin-right: 0.5em;"><a id="x1-4003r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">#</span></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">include</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">&lt;cstdio&gt;</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-4004r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-4005r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">void</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">foo(</span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">int</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">* x) {</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-4006r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtti-10x-x-90" style="font-size: 90%; font-family: monospace,monospace; font-style: italic;">        </span><span style="color:#000000"><span class="ec-lmtti-10x-x-90" style="font-size: 90%; font-family: monospace,monospace; font-style: italic;">//</span></span><span style="color:#000000"> <span class="ec-lmtti-10x-x-90" style="font-size: 90%; font-family: monospace,monospace; font-style: italic;">does nothing</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-4007r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">}</span></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-4008r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-4009r7" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">int</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">main() {</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-4010r8" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">int</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">x;</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-4011r9" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">foo</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">(&amp;</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">x</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">);</span></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-4012r10" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">printf</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">(</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">"</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">%</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">d</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">\</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">n</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">"</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">,</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">x);</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-4013r11" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">return</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">0;</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-4014r12" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">}</span></span></pre>


<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 5: </span><span class="content">Function Scope Escape Uninitialized Variable</span></figcaption>
<!-- tex4ht:label?: x1-4014r  -->


<!-- l. 82 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">
</p>
   

<h4 class="likesubsectionHead" style="line-height: 1.2; font-size: 1.3195em;"><a id="x1-5000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Example 3: Uninitialized Class Member</h4>


<!-- l. 84 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Consider the example in Listing <a href="#x1-5001r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">6<!-- tex4ht:ref: lst:20250707:6  --></a>. The private member variable <span class="ec-lmtt-10" style="font-family: monospace,monospace;">m_x </span>is used uninitialized without any warning from
the same GCC version as the previous examples.
</p>
   

<!-- l. 86 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-5001r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>
<a id="x1-5002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>   
</p>
<pre class="lstlisting" id="listing-6" style="font-family: monospace,monospace; white-space: pre-wrap; margin-top: 0.5em; margin-bottom: 0.5em; background-color: #BFBFBF;"><span class="label" style="margin-right: 0.5em;"><a id="x1-5003r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">#</span></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">include</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">&lt;cstdio&gt;</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-5004r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-5005r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">class</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">MyClass {</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-5006r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">int</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">m_x;</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-5007r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-5008r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">public</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">:</span></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-5009r7" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">               </span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">void</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">print() {</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-5010r8" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">                       </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">printf</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">(</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">"</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">%</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">d</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">\</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">n</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">"</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">,</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">m_x);</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-5011r9" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">               </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">}</span></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-5012r10" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">};</span></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-5013r11" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-5014r12" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">int</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">main() {</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-5015r13" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">MyClass</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">obj;</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-5016r14" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">obj</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">.</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">print</span></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">();</span></span> 
<span class="label" style="margin-right: 0.5em;"><a id="x1-5017r15" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span style="color:#000000"><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">return</span></span><span style="color:#000000"> <span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">0;</span> 
</span><span class="label" style="margin-right: 0.5em;"><a id="x1-5018r16" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span style="color:#000000"><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">}</span></span></pre>


<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 6: </span><span class="content">Class Member Uninitialized</span></figcaption>
<!-- tex4ht:label?: x1-5018r  -->


<!-- l. 105 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">
</p>
   

<h4 class="likesubsectionHead" style="line-height: 1.2; font-size: 1.3195em;"><a id="x1-6000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Conclusion</h4>


<!-- l. 107 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">While the <span class="ec-lmtt-10" style="font-family: monospace,monospace;">-Wall </span>flag does provide some protection by detecting simple instances of CWE-457, many common cases
remain undetected. The SwA team generally recommends developers follow industry best practices—such
as always initializing variables—and use static analysis tools whenever practical to help detect this
issue.
                                                                                         
                                                                                         
</p>
   

<h3 class="sectionHead" style="line-height: 1.2; font-size: 1.5157em;"><a id="x1-7000" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>References</h3>


<!-- l. 52 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">    
</p>


<dl class="thebibliography"><dt class="thebibliography" id="X0-20250707_cwe-457" style="float: left; clear: left; margin-right: 1em;">
[1]  
</dt><dd class="thebibliography" id="bib-1" style="margin-left: 2.5em;">
<!-- l. 52 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0_20250707_cwe-457" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>CWE   Content   Team.    “CWE-457:    Use   of   Uninitialized   Variable”.    In:    (2025).    <span class="small-caps" style="font-variant: small-caps;">url</span>:    
<a class="url" href="https://cwe.mitre.org/data/definitions/457.html" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://cwe.mitre.org/data/definitions/457.html</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-swatips" style="float: left; clear: left; margin-right: 1em;">
[2]  
</dt><dd class="thebibliography" id="bib-2" style="margin-left: 2.5em;">
<!-- l. 52 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0_swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon Hood, ed. <span class="uline" style="text-decoration: underline;">SwATips</span>. <a class="url" href="https://www.SwATips.com/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.SwATips.com/</span></a>.</p></dd></dl>

 

]]></description>
	</item>
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
<p class="noindent" style="margin-top: 0; margin-bottom: 0;"><span class="ec-lmr-8" style="font-size: 80%;">Updated Monday 12</span><sup class="textsuperscript"><span class="ec-lmr-9" style="font-size: 90%;">th</span></sup><span class="ec-lmr-8" style="font-size: 80%;"> May, 2025</span>
</p>
<!-- l. 1 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Last year, Cybersecurity leadership in the U.S. encouraged organizations to use memory-safe programming
languages. I criticized the blanket recommendation[<a id="x1-1001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0_20250512_hood2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2</a>] as a partial solution for a more serious underlying concern in
developer training, citing the problems faced with legacy Ada code[<a id="x1-1002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0_20250512_hood" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1</a>, <a id="x1-1003" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0_20250512_keen" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">4</a>]. Recently, I have had the privilege of sitting
through lengthy meetings extoling the virtues of memory-safe languages and creating policies that enumerate the
languages that developers must use for certain contracts. In spite of all the warnings, it looks like certain
government agencies are pushing ahead with the recommendation.
</p>
<!-- l. 3 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   But is requiring a memory-safe language the panacea to memory safety? Certainly not! Heap inspections, logical
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
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Consider the situation of a linked list where one node references an earlier node. This thought experiment using
two nodes is demonstrated in Listing <a href="#x1-3001r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1<!-- tex4ht:ref: lst:20250512:leak  --></a>. In this code, a linked list results in a circular reference. In
Rust, the memory is always referenced by itself, resulting in it never getting freed when it goes out of
scope.
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
Rust and other memory-safe languages are ushering in a new age of security-conscious development. Proposals for
memory-safe C++, safety-critical Rust technologies like Ferrocene, and even experimental borrow checkers in
other languages have exploded onto the scene. The benefits of Rust cannot be overstated, and the
second-order effects of the Rust community on other programming languages will have good and meaningful
cybersecurity enhancements for developers who may never have a desire to learn it. The programming
landscape is changing. Just as Chrome OS wouldn’t exist as it does today without Gentoo Linux,
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
<!-- l. 52 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0_swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon Hood, ed. <span class="uline" style="text-decoration: underline;">SwATips</span>. <a class="url" href="https://www.SwATips.com/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.SwATips.com/</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-20250512_keen" style="float: left; clear: left; margin-right: 1em;">
[4]  
</dt><dd class="thebibliography" id="bib-4" style="margin-left: 2.5em;">
<!-- l. 52 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0_20250512_keen" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Kevin    Keen.    “Ada    <span class="sout" style="text-decoration: line-through;">Low</span>High    Integrity    Profiles”.    In:    <span class="uline" style="text-decoration: underline;">SwATips.com</span>    (2021).    <span class="small-caps" style="font-variant: small-caps;">url</span>:    
<a class="url" href="https://www.swatips.com/articles/20210809.html" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.swatips.com/articles/20210809.html</span></a>.</p></dd></dl>

 

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
