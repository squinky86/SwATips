	<item>
		<title>Ever-Changing Encryption Standards</title>
		<link>https://www.SwATips.com/articles/20220328.html</link>
		<pubDate>Mon, 28 Mar 2022 00:00:00 -0500</pubDate>
<description><![CDATA[

<p style="margin-top: 0; margin-bottom: 0;"><a href="/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/swatips.svg" width="120" alt="SwATips" style="border-top: 0; border-left: 0; border-right: 0;"/></a>| <a href="articles/20220328.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">pdf</a> | <a rel="license" href="http://creativecommons.org/licenses/by/4.0/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/by.svg" width="60" height="21" alt="CC-BY" style="border-top: 0; border-left: 0; border-right: 0;"/></a></p>


<div class="maketitle" style="margin-top: 1em; text-align: center; margin-bottom: 2em;">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead" style="text-align: center;"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a href="#cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">3</a>]<br/>
</h2>
<div class="author" style="text-align: center;"><span class="rm-lmr-12" style="font-size: 120%;">Jon Hood</span></div><br/>
<div class="date" style="text-align: center;"><span class="rm-lmr-12" style="font-size: 120%;">Monday 28</span><sup class="textsuperscript"><span class="rm-lmr-9" style="font-size: 90%;">th</span></sup><span class="rm-lmr-12" style="font-size: 120%;"> March, 2022</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead"><span class="titlemark">1   </span> <a id="x1-10001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Ever-Changing Encryption Standards</h3>


<!-- l. 44 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;"><span class="rm-lmr-8" style="font-size: 80%;">Updated Monday 28</span><sup class="textsuperscript"><span class="rm-lmr-9" style="font-size: 90%;">th</span></sup><span class="rm-lmr-8" style="font-size: 80%;"> March, 2022</span>
</p>
<!-- l. 1 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Since 2016, National Security Systems (NSS) have been required to implement the policies put forward by the
Committee on National Security Systems (CNSS). CNSS Policy 15 details key sizes that are required to
protect national security information.[<a href="#cite.0@20220328:cnssp15" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2</a>] To comply with CNSSP 15, system architects should use an
algorithm approved in the Commercial National Security Algorithm (CNSA) suite at a key size defined by
CNSSP 15. At the time of this writing, the following algorithms are permitted for encrypting data:
</p>
     

<ul class="itemize1">
<li class="itemize">AES with 256-bit keys
</li>     
<li class="itemize">RSA with at least 3072-bit modulus
</li>     
<li class="itemize">ECC with P-384</li></ul>


<!-- l. 7 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Additional requirements for key exchange and digital signatures are also provided in the policy.
</p>
<!-- l. 9 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Not only must the CNSSP 15 standards be implemented, but also the recommendations of NIST SP 800-57.[<a href="#cite.0@20220328:nist80057p1r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1</a>]
Currently, the following algorithms are allowed by SP 800-57 Part 1 Rev. 5: </p>


<ul class="itemize1">     
<li class="itemize">AES with 128, 192, or 256-bit key sizes
</li>     
<li class="itemize">RSA with at least 3072-bit modulus
</li>     
<li class="itemize">ECC with a range of at least 256 (i.e. P-256, P-384, and P-512)</li></ul>


<!-- l. 15 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">NIST SP 800-57 further details that RSA with a 15360-bit modulus and an Elliptic Curve of at least 512 bits are
required to reach the security afforded by AES-256 (the minimum AES key size allowed by CNSSP 15). While
RSA15360 is permitted under CNSSP 15, P-512 is not.
</p>
<!-- l. 17 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   For the near future, AES-256, RSA3072, and P-384 are the permitted minimum standards for cryptography.
Engineers implementing RSA3072 or P-384 for their encryption should be ready to move to RSA15360 and P-512
respectively in anticipation of updated CNSS standards.
                                                                                         
                                                                                         
</p>
   

<h3 class="sectionHead"><a id="x1-20001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>References</h3>


<!-- l. 49 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">    
</p>


<dl class="thebibliography"><dt class="thebibliography" id="X0-20220328:nist80057p1r5" style="float: left; clear: left; margin-right: 1em;">
[1]  
</dt><dd class="thebibliography" id="bib-1" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20220328:nist80057p1r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Elaine Barker. Recommendation for Key Management. Part 1 – General. Tech. rep. Special Publication
(SP)              800-57              Part              1              Revision              5.              Washington,
D.C.: National Institute of Standards and Technology, 2020. <span class="small-caps" style="font-variant: small-caps;">doi</span>: <a href="https://doi.org/10.6028/NIST.SP.800-57pt1r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">10.6028/NIST.SP.800-57pt1r5</span></a>.
<span class="small-caps" style="font-variant: small-caps;">url</span>: <a class="url" href="https://nvlpubs.nist.gov/nistpubs/SpecialPublications/NIST.SP.800-57pt1r5.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://nvlpubs.nist.gov/nistpubs/SpecialPublications/NIST.SP.800-57pt1r5.pdf</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-20220328:cnssp15" style="float: left; clear: left; margin-right: 1em;">
[2]  
</dt><dd class="thebibliography" id="bib-2" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20220328:cnssp15" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Committee                     on                     National                     Security                     Systems.
Use of Public Standards for Secure Information Sharing
. Tech. rep. CNSSP 15. Ft. Meade, MD: NSA,
2016. <span class="small-caps" style="font-variant: small-caps;">url</span>: <a class="url" href="https://www.cnss.gov/CNSS/issuances/Policies.cfm" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.cnss.gov/CNSS/issuances/Policies.cfm</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-swatips" style="float: left; clear: left; margin-right: 1em;">
[3]  
</dt><dd class="thebibliography" id="bib-3" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon Hood, ed. SwATips. <a class="url" href="https://www.SwATips.com/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.SwATips.com/</span></a>.</p></dd></dl>

 

]]></description>
	</item>
	<item>
		<title>The Death of CentOS on DoD Networks</title>
		<link>https://www.SwATips.com/articles/20220321.html</link>
		<pubDate>Mon, 21 Mar 2022 00:00:00 -0500</pubDate>
<description><![CDATA[

<p style="margin-top: 0; margin-bottom: 0;"><a href="/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/swatips.svg" width="120" alt="SwATips" style="border-top: 0; border-left: 0; border-right: 0;"/></a>| <a href="articles/20220321.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">pdf</a> | <a rel="license" href="http://creativecommons.org/licenses/by/4.0/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/by.svg" width="60" height="21" alt="CC-BY" style="border-top: 0; border-left: 0; border-right: 0;"/></a></p>


<div class="maketitle" style="margin-top: 1em; text-align: center; margin-bottom: 2em;">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead" style="text-align: center;"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a href="#cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">3</a>]<br/>
</h2>
<div class="author" style="text-align: center;"><span class="rm-lmr-12" style="font-size: 120%;">Jon Hood</span></div><br/>
<div class="date" style="text-align: center;"><span class="rm-lmr-12" style="font-size: 120%;">Monday 21</span><sup class="textsuperscript"><span class="rm-lmr-9" style="font-size: 90%;">st</span></sup><span class="rm-lmr-12" style="font-size: 120%;"> March, 2022</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead"><span class="titlemark">1   </span> <a id="x1-10001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>The Death of CentOS on DoD Networks</h3>


<!-- l. 44 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;"><span class="rm-lmr-8" style="font-size: 80%;">Updated Tuesday 22</span><sup class="textsuperscript"><span class="rm-lmr-9" style="font-size: 90%;">nd</span></sup><span class="rm-lmr-8" style="font-size: 80%;"> March, 2022</span>
</p>
<!-- l. 1 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   When selecting an operating system for a new DoD product, there are several factors that are considered. The
top three factors we often see are:
</p>
     

<ol class="enumerate1" style="list-style-type: decimal;">
<li id="x1-1002x1" class="enumerate">     
Price
</li>     
<li id="x1-1004x2" class="enumerate">
DoD Compliance
</li>     
<li id="x1-1006x3" class="enumerate">
Ease of Setup</li></ol>


<!-- l. 8 -->
<p class="indent" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   When CentOS, recently acquired by RedHat, announced that they would no longer support CentOS 8 at the end
of 2021,[<a href="#cite.0@20220321:centos-eol" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1</a>] architects began looking for an alternative. The possible alternatives that will be explored are:
</p>
     

<ul class="itemize1">
<li class="itemize">RedHat Enterprise Linux 8
</li>     
<li class="itemize">Oracle Linux 8
</li>     
<li class="itemize">Rocky Linux 8
</li>     
<li class="itemize">AlmaLinux OS 8
</li>     
<li class="itemize">Ubuntu 20.04
</li>     
<li class="itemize">SUSE Linux Enterprise Server 15</li></ul>


<!-- l. 18 -->
<p class="indent" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   Each of these alternatives will be discussed here along with considerations DoD projects must make before they
implement one of them. The minimal installation for each of the options is selected, and an install of Tenable Nessus
10.1.1 (commercially known as ACAS) will be used to evaluate compatibility.
</p>
<!-- l. 20 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.1   </span> <a id="x1-20001.1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>RedHat Enterprise Linux 8</h4>


<!-- l. 22 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">The first competitor is the seasoned veteran of the group: RHEL. One of the benefits of CentOS 8 is that
it has been binary compatible with RHEL. Everything works out of the box, including DISA STIG
compliance, SCAP Compliance Checker, and Nessus scanning. The downside to this option is the recurring
subscription cost. Some organizations have a difficult time funding material and license purchases
(i.e. labor-cost-only contracts), It’s often difficult to use a subscription-based service contractually, even if the cost
is reasonable.
                                                                                         
                                                                                         
</p>
<!-- l. 24 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.2   </span> <a id="x1-30001.2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Oracle Linux 8</h4>


<!-- l. 26 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Oracle Linux is now the oldest kid on the block when it comes to RHEL-compatible alternatives. A
DISA STIG already exists for compliance, and a beta benchmark is available which knocks out the
majority of automated checks in the STIG. For a streamlined experience in regards to compliance and
compatibility, Oracle Linux 8 should be at the top of the list for consideration. The Nessus 10.1.1
ES8 RPM works with Oracle Linux 8, and the Oracle Linux 8 distribution is expressly supported by
Tenable.
</p>
<!-- l. 28 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.3   </span> <a id="x1-40001.3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Rocky Linux 8</h4>


<!-- l. 29 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Rocky Linux is one of the newer RHEL-binary-compatible rebuilds that attempts to recreate the RHEL
environment using the same standards that CentOS 8 used before it went EOL.
</p>
<!-- l. 31 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h5 class="subsubsectionHead"><span class="titlemark">1.3.1   </span> <a id="x1-50001.3.1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Installation Issues</h5>


<!-- l. 32 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">When applying the DISA STIG for Red Hat Enterprise Linux 8 security profile during installation, it does not
appear that the majority of the checks and configuration options (eg: partition information) are being
performed or configured. Additionally, installing with this security profile will require the installation of
openscap which will crash the installer with the minimal installation media. Rocky’s inability to maintain
compatibility with RHEL’s security baselines (when both AlmaLinux and Oracle Linux were able to do so) is
concerning.
</p>
<!-- l. 34 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h5 class="subsubsectionHead"><span class="titlemark">1.3.2   </span> <a id="x1-60001.3.2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Compliance</h5>


<!-- l. 35 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Rocky Linux does not currently have DISA risk acceptance or a standard STIG to apply. Instead, the RHEL 8
benchmark can be utilized with a note that the checks against the <span class="ec-lmtt-10" style="font-family: monospace,monospace;">CPE_NAME </span>in <span class="ec-lmtt-10" style="font-family: monospace,monospace;">/etc/os-release </span>should be
modified to look for Rocky Linux rather than RHEL. The benchmark file (such as the one installed
with SCAP Compliance Checker) can be modified to work with Rocky Linux using the command in
Listing <a href="#x1-6001r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1<!-- tex4ht:ref: lst:20220321:rocky  --></a>.
</p>
   

<!-- l. 37 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-6001r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-6002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>


<div id="listing-1" class="lstlisting" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-6003r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtti-10x-x-90" style="font-size: 90%; font-family: monospace,monospace; font-style: italic;"># sed -i -e </span><span class="ts1-lmtti10-x-x-90" style="font-size: 90%;">'</span><span class="ec-lmtti-10x-x-90" style="font-size: 90%; font-family: monospace,monospace; font-style: italic;">s|redhat:enterprise_linux\(.*\)&lt;/pattern&gt;|rocky:rocky\1*&lt;/pattern&gt;|g</span><span class="ts1-lmtti10-x-x-90" style="font-size: 90%;">'</span><span class="ec-lmtti-10x-x-90" style="font-size: 90%; font-family: monospace,monospace; font-style: italic;"> \</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-6004r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        /opt/scc/Resources/Content/SCAP12_Content/U_RHEL_8_*_STIG_SCAP_1-2_Benchmark.xml</span>
<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 1:</span><span class="content">Modify
RHEL
Benchmark
for
Rocky
Linux</span></figcaption><!-- tex4ht:label?: x1-6001r1  -->
   
</div>


<!-- l. 42 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   If using the RHEL benchmark for evaluating Rocky Linux, the SCAP content will flag on rules relating to using
a supported release (it checks /etc/redhat-release for this) and RedHat certificate authorities. The check content for
                                                                                         
                                                                                         
these two CAT I checks should be modified to reflect the Rocky Linux support lifecycle and certificate authorities
respectively.
</p>
<!-- l. 44 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h5 class="subsubsectionHead"><span class="titlemark">1.3.3   </span> <a id="x1-70001.3.3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Compatibility</h5>


<!-- l. 45 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">I had no problem installing the RHEL version of Nessus 10.1.1 (though it should be noted that Rocky Linux is not
listed as an officially supported distribution by Tenable). All RHEL packages installed and ran without issues, as
they did with CentOS 8. FIPS compliance was enabled and tested with the <span class="ec-lmtt-10" style="font-family: monospace,monospace;">fips-mode-setup --enable</span>
command.
</p>
<!-- l. 47 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.4   </span> <a id="x1-80001.4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>AlmaLinux OS 8</h4>


<!-- l. 48 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">AlmaLinux OS 8, like Rocky Linux, is one of the newcomers that is attempting to court CentOS migrators.
</p>
<!-- l. 50 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h5 class="subsubsectionHead"><span class="titlemark">1.4.1   </span> <a id="x1-90001.4.1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Installation Issues</h5>


<!-- l. 51 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">The first thing that should be noted is the presence of a security profile for “DISA STIG for AlmaLinux 8.” It should
be emphasized that DISA has not released such a STIG, and the implications of there being one is disconcerting
from a DoD compliance point of view. A bug has been created with the AlmaLinux team to address this.[<a href="#cite.0@20220321:almabug" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2</a>]
Additionally, installing with this security profile selected against the minimal installation media will result in a crash
due to an inability to install openscap.
</p>
<!-- l. 53 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h5 class="subsubsectionHead"><span class="titlemark">1.4.2   </span> <a id="x1-100001.4.2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Compliance</h5>


<!-- l. 54 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">AlmaLinux does not currently have DISA risk acceptance or a standard STIG to apply. Instead, the RHEL 8
benchmark can be utilized with a note that the checks against the <span class="ec-lmtt-10" style="font-family: monospace,monospace;">CPE_NAME </span>in <span class="ec-lmtt-10" style="font-family: monospace,monospace;">/etc/os-release </span>should be
modified to look for AlmaLinux rather than RHEL. The benchmark file (such as the one installed
with SCAP Compliance Checker) can be modified to work with AlmaLinux using the command in
Listing <a href="#x1-10001r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2<!-- tex4ht:ref: lst:20220321:alma  --></a>.
</p>
   

<!-- l. 56 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-10001r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-10002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>


<div id="listing-2" class="lstlisting" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-10003r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtti-10x-x-90" style="font-size: 90%; font-family: monospace,monospace; font-style: italic;"># sed -i -e </span><span class="ts1-lmtti10-x-x-90" style="font-size: 90%;">'</span><span class="ec-lmtti-10x-x-90" style="font-size: 90%; font-family: monospace,monospace; font-style: italic;">s|redhat:enterprise_linux\(.*\)&lt;/pattern&gt;|almalinux:almalinux\1*&lt;/pattern&gt;|g</span><span class="ts1-lmtti10-x-x-90" style="font-size: 90%;">'</span><span class="ec-lmtti-10x-x-90" style="font-size: 90%; font-family: monospace,monospace; font-style: italic;"> \</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-10004r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        /opt/scc/Resources/Content/SCAP12_Content/U_RHEL_8_*_STIG_SCAP_1-2_Benchmark.xml</span>
<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 2:</span><span class="content">Modify
RHEL
Benchmark
for
AlmaLinux</span></figcaption><!-- tex4ht:label?: x1-10001r1  -->
   
</div>


<!-- l. 61 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   If using the RHEL baseline for evaluating AlmaLinux, the SCAP content will flag for rules relating to using a
supported release (it checks /etc/redhat-release for this) and RedHat certificate authorities. The check content for
these two CAT I checks should be modified to reflect the AlmaLinux support lifecycle and certificate authorities
                                                                                         
                                                                                         
respectively.
</p>
<!-- l. 63 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h5 class="subsubsectionHead"><span class="titlemark">1.4.3   </span> <a id="x1-110001.4.3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Compatibility</h5>


<!-- l. 64 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">I had no problem installing the RHEL version of Nessus 10.1.1 (though it should be noted that AlmaLinux is not
listed as an officially supported distribution by Tenable). All RHEL packages installed and ran without issues, as
they did with CentOS 8. FIPS compliance was enabled and tested with the <span class="ec-lmtt-10" style="font-family: monospace,monospace;">fips-mode-setup --enable</span>
command.
</p>
<!-- l. 66 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.5   </span> <a id="x1-120001.5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Ubuntu 20.04</h4>


<!-- l. 68 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">For workstation use, Ubuntu is one of my go-to distributions. Nevertheless, a switch from CentOS to Ubuntu
involves an architectural change that must be designed in up front rather than providing a drop-in replacement for
end-of-life CentOS software. Installation of Nessus on Ubuntu 20.04 resulted in some manual modifications before it
was able to work, and it should be noted that upgrading from Ubuntu 20.04 to the development branch of 22.04
(Jammy Jellyfish) resulted in a non-functioning Nessus installation. Nessus doesn’t support Debian 11 or Ubuntu
22.04 at this time.
</p>
<!-- l. 70 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.6   </span> <a id="x1-130001.6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>SUSE Enterprise Linux 15</h4>


<!-- l. 72 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">The final option is SLES 15. Like RHEL, it provides enterprise-level subscription-based support. SLES 15
includes STIG content, SCAP benchmarks, and a seamless installation for products such as Nessus.
SCAP content has lagged behind its RHEL counterparts; however, the support lifecycle for SLES 15
allows DoD project planners to have the security of knowing that their underlying operating system
will be supported through July 31, 2031. It should also be noted that the STIG and SCAP content
are for the enterprise server product, while the RHEL and Oracle products include their workstation
derivatives.
</p>
<!-- l. 74 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.7   </span> <a id="x1-140001.7" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Concluding Remarks</h4>


<!-- l. 76 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">If you are a DoD product designer and needing to switch from CentOS 8, you have a lot of options. The most
painless (compliance-wise) is to switch to Oracle Linux or RHEL. With either of these options, you have a robust
STIG compliance framework in place to justify the decisions and a support network that can be used if needed.
Nevertheless, Oracle Linux isn’t the only free option to consider: strong contenders from AlmaLinux and Rocky
Linux provide compatibility with very minor compliance caveats. Instead of the General Purpose OS STIG, the
RHEL STIG can be modified to record compliance status of these operating systems; however, the AO should be
informed of the risks involving using software managed by the Rocky and Alma organizations. These organizations
are new and don’t have the prodigy of RedHat, Oracle, SUSE, or Canonical in working with DoD
projects.
</p>
<!-- l. 78 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Can the Authorizing Official (AO) accept the risk of allowing the AlmaLinux OS Foundation or Rocky
Enterprise Software Foundation having write/update permissions to their package repositories? Both organizations
already have the backing of Amazon, Microsoft, and Google platforms; such big names are members of
these foundations to help their governance and future direction. The current lack of DoD-level risk
acceptance should be acknowledged by the AO, but such an acceptance should not be seen as a high
risk.
                                                                                         
                                                                                         
</p>
<!-- l. 80 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Finally, AlmaLinux supports the ELevate project which allows users to move to AlmaLinux, Rocky Linux, and
Oracle Linux from CentOS 7 (<a href="https://wiki.almalinux.org/elevate/" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://wiki.almalinux.org/elevate/</span></a>), and there are a few other tools available
for migrating from CentOS 8 to one of the supported RHEL variants.
                                                                                         
                                                                                         
</p>
   

<h3 class="sectionHead"><a id="x1-150001.7" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>References</h3>


<!-- l. 49 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">    
</p>


<dl class="thebibliography"><dt class="thebibliography" id="X0-20220321:centos-eol" style="float: left; clear: left; margin-right: 1em;">
[1]  
</dt><dd class="thebibliography" id="bib-1" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20220321:centos-eol" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>CentOS.            CentOS Linux EOL.            CentOS.            Dec. 31,            2021.            <span class="small-caps" style="font-variant: small-caps;">url</span>:
<a href="https://www.centos.org/centos-linux-eol/" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.centos.org/centos-linux-eol/</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-20220321:almabug" style="float: left; clear: left; margin-right: 1em;">
[2]  
</dt><dd class="thebibliography" id="bib-2" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20220321:almabug" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon        Hood.        AlmaLinux Bug Tracker.        AlmaLinux.        Mar. 21,        2022.        <span class="small-caps" style="font-variant: small-caps;">url</span>:
<a href="https://bugs.almalinux.org/view.php?id=202" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://bugs.almalinux.org/view.php?id=202</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-swatips" style="float: left; clear: left; margin-right: 1em;">
[3]  
</dt><dd class="thebibliography" id="bib-3" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon Hood, ed. SwATips. <a href="https://www.SwATips.com/" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.SwATips.com/</span></a>.</p></dd></dl>

 

]]></description>
	</item>
	<item>
		<title>So you put an Unclassified CD in a Classified Machine</title>
		<link>https://www.SwATips.com/articles/20220131.html</link>
		<pubDate>Mon, 31 Jan 2022 00:00:00 -0600</pubDate>
<description><![CDATA[

<p style="margin-top: 0; margin-bottom: 0;"><a href="/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/swatips.svg" width="120" alt="SwATips" style="border-top: 0; border-left: 0; border-right: 0;"/></a>| <a href="articles/20220131.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">pdf</a> | <a rel="license" href="http://creativecommons.org/licenses/by/4.0/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/by.svg" width="60" height="21" alt="CC-BY" style="border-top: 0; border-left: 0; border-right: 0;"/></a></p>


<div class="maketitle" style="margin-top: 1em; text-align: center; margin-bottom: 2em;">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead" style="text-align: center;"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a href="#cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">3</a>]<br/>
</h2>
<div class="author" style="text-align: center;"><span class="rm-lmr-12" style="font-size: 120%;">Jon Hood</span></div><br/>
<div class="date" style="text-align: center;"><span class="rm-lmr-12" style="font-size: 120%;">Monday 31</span><sup class="textsuperscript"><span class="rm-lmr-9" style="font-size: 90%;">st</span></sup><span class="rm-lmr-12" style="font-size: 120%;"> January, 2022</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead"><span class="titlemark">1   </span> <a id="x1-10001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>So you put an Unclassified CD in a Classified Machine</h3>


<!-- l. 44 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;"><span class="rm-lmr-8" style="font-size: 80%;">Updated Tuesday 1</span><sup class="textsuperscript"><span class="rm-lmr-9" style="font-size: 90%;">st</span></sup><span class="rm-lmr-8" style="font-size: 80%;"> February, 2022</span>
</p>
<!-- l. 1 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   <i>NOTE:</i> When in doubt, it’s always appropriate to ask your security office for guidance. Hiding a potential
mistake carries a greater penalty than admitting a mistake that turns out to be insignificant. The scenario in this
article is contrived. If you got here from a search engine because you’re wondering if you should report a security
incident, you should probably go ahead and call your security officer that you are investigating a possible
incident. They have the authority to establish enhanced rules and should have the expertise to help
you.
</p>
<!-- l. 3 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.1   </span> <a id="x1-20001.1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>A Nervous Newbie</h4>


<!-- l. 5 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">It had already been a long, stressful day at work when the panicked, young professional sheepishly knocked on my
door to report that they “did a dumb.” The terror in his voice made me think that he had either
given classified information to a hostile government or that he was a spy admitting that he wanted to
defect.
</p>
<!-- l. 7 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   But the truth was much more benign. This young employee had taken a finalized, unclassified,
properly-marked CD-R with some unclassified software on it and loaded the software onto his shiny new classified
analysis machine. After he finished the installation, he placed the CD beside the machine and continued
working, only to notice his coworker installing the software on her new unclassified machine a little while
later.
</p>
<!-- l. 9 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   These two young employees had been trained that a CD-R placed onto a classified computer makes the CD go to
the classification of the information system it’s placed on. They then did the right thing–unplug the lower-classified
machine and report a possible security violation.
</p>
<!-- l. 11 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Certainly, each information system can have its own requirements for how to handle such a scenario, but in
general, the DoD and Army have published guidance and minimum security requirements for how to handle such
things. There are two things that can go classified in the above scenario: the storage media and the data on
it.
</p>
<!-- l. 13 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.2   </span> <a id="x1-30001.2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>The Data</h4>


<!-- l. 14 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Security violations always receive priority handling of everyone involved. It’s an immediate “stop work and fix it”
scenario. But the data involved was inconsequential: an installer for a common word processor that had nice text
markup for the programming languages these employees were analyzing. The data was unimportant from a security
and OPSEC standpoint; it was data that was already publicly released and freely available on the
internet.
</p>
<!-- l. 16 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Had the employees loaded data of a higher classification onto a lower-classified machine, we’d have what’s known
as a spillage event, and the data owners of the higher classified data would have the authority to dictate cleanup
procedures that we would follow.
</p>
<!-- l. 18 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.3   </span> <a id="x1-40001.3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>The Media</h4>


<!-- l. 19 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">I recognized the media immediately. It was a CD I had burned with analysis tools the previous month. My practice
is to burn a single-session UDF CD that can be written only once to help mitigate the risk of security
violations for this specific scenario. I breathed a sigh of relief when they brought the finalized CD to
me.
                                                                                         
                                                                                         
</p>
<!-- l. 21 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   The metric for increasing the classification of removable media is “if the level of classification of the information
on the medium changes.”[<a href="#cite.0@20220202:dodm520001mvol2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1</a>, § 4.b] The information system that the CD was being used on permits the use of data
diodes (one-way data connections from low to high). I could verify that the classified machine could
not and did not write data to the CD. You can see this metric for classified media documented in
the examples of DA PAM 25-2-13. Section 4-7.a–b gives the requirements for when inserting a SIPR
token into a NIPR computer is and is not a security violation. Section 4-7.c gives the scenarios for
declaring a security incident when a NIPR token is inserted into a SIPR machine, pointing out that
the metric for an incident is “if classified data were written to the token, or if malicious code was
introduced.”[<a href="#cite.0@20220202:dapam25-2-13" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2</a>] Merely inserting a NIPR token into a properly-configured SIPR machine is not a security
incident, just like inserting any other unclassified media into a classified machine may not be a security
incident.
</p>
<!-- l. 23 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.4   </span> <a id="x1-50001.4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Conclusion</h4>


<!-- l. 24 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Each information system’s security department is different and defines its own rules for when removable media can
go classified. There is always the possible scenario where an important tactical mission is using a Sega Dreamcast
that reads discs from the outside inward, making it possible to write classified data to the end of a finalized CD or
DVD. That’s why security offices exist, and reporting a possible security violation is asking those officers to perform
a role they’re already being paid to do.
</p>
<!-- l. 26 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   In the situation documented above, the optical drive was incapable of burning data to a properly finalized,
non-rewritable disc. All of the possible filesystem records were checked for modification, and the security office was
called to verify that there were no additional security policies documented governing the insertion of unclassified,
write-protected media into a classified environment.
</p>
<!-- l. 28 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Nevertheless, you can help by using data diodes, properly marking media, finalizing non-rewritable CDs and
DVDs, and verifying the state of finalized/write-protected media when it is inserted into higher-classification
environments. Remember that optical media often has multiple filesystem tables that must be verified (often Joilet
and UDF).
                                                                                         
                                                                                         
</p>
   

<h3 class="sectionHead"><a id="x1-60001.4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>References</h3>


<!-- l. 49 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">    
</p>


<dl class="thebibliography"><dt id="X0-20220202:dodm520001mvol2" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[1]  
</dt><dd id="bib-1" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20220202:dodm520001mvol2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Department  of  Defense.  Department of Defense Manual 5200.01 Volume 2.  Tech.  rep.  Incorporating
Change  4,  Effective  July  28,  2020.  Washington,  D.C.:  Department  of  Defense,  2020.  <span class="small-caps" style="font-variant: small-caps;">url</span>:
<a href="https://www.esd.whs.mil/Portals/54/Documents/DD/issuances/dodm/520001m_vol2.pdf" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.esd.whs.mil/Portals/54/Documents/DD/issuances/dodm/520001m_vol2.pdf</span></a>.
</p>    
</dd>
<dt id="X0-20220202:dapam25-2-13" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[2]  
</dt><dd id="bib-2" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20220202:dapam25-2-13" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Department of the Army. Department of the Army Pamphlet 25–2–13. Army Identity, Credential, and Access Management and Public Key Infrastructure Implementing Instructions.
Tech. rep. Washington, D.C.: Department of the Army, 2019. <span class="small-caps" style="font-variant: small-caps;">url</span>: <a href="https://armypubs.army.mil/epubs/DR_pubs/DR_a/pdf/web/ARN17425_P25_2_13_Admin_FINAL.pdf" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://armypubs.army.mil/epubs/DR_pubs/DR_a/pdf/web/ARN17425_P25_2_13_Admin_FINAL.pdf</span></a>.
</p>    
</dd>
<dt id="X0-swatips" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[3]  
</dt><dd id="bib-3" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon Hood, ed. SwATips. <a href="https://www.SwATips.com/" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.SwATips.com/</span></a>.</p></dd></dl>

 

]]></description>
	</item>
	<item>
		<title>GCC as a Static Analysis Tool</title>
		<link>https://www.SwATips.com/articles/20211220.html</link>
		<pubDate>Mon, 20 Dec 2021 00:00:00 -0600</pubDate>
<description><![CDATA[

<p style="margin-top: 0; margin-bottom: 0;"><a href="/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/swatips.svg" width="120" alt="SwATips" style="border-top: 0; border-left: 0; border-right: 0;"/></a>| <a href="articles/20211220.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">pdf</a> | <a rel="license" href="http://creativecommons.org/licenses/by/4.0/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/by.svg" width="60" height="21" alt="CC-BY" style="border-top: 0; border-left: 0; border-right: 0;"/></a></p>


<div class="maketitle" style="margin-top: 1em; text-align: center; margin-bottom: 2em;">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead" style="text-align: center;"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a href="#cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1</a>]<br/>
</h2>
<div class="author" style="text-align: center;"><span class="rm-lmr-12" style="font-size: 120%;">Andrea Barnes</span></div><br/>
<div class="date" style="text-align: center;"><span class="rm-lmr-12" style="font-size: 120%;">Monday 20</span><sup class="textsuperscript"><span class="rm-lmr-9" style="font-size: 90%;">th</span></sup><span class="rm-lmr-12" style="font-size: 120%;"> December, 2021</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead"><span class="titlemark">1   </span> <a id="x1-10001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>GCC as a Static Analysis Tool</h3>


<!-- l. 44 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;"><span class="rm-lmr-8" style="font-size: 80%;">Updated Wednesday 15</span><sup class="textsuperscript"><span class="rm-lmr-9" style="font-size: 90%;">th</span></sup><span class="rm-lmr-8" style="font-size: 80%;"> December, 2021</span>
</p>
<!-- l. 1 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   A new static analysis feature has been released with GCC-10 and GCC-11. David Malcom is a Redhat Developer
on the GCC project who has implemented <span class="ec-lmtt-10" style="font-family: monospace,monospace;">-fanalyzer</span>: “A static analysis pass to identify various problems at
compile-time, rather than at runtime.”[<a href="#cite.0@20211220:gcc10" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2</a>] This analyzer writes security issues to the console using the
<span class="ec-lmtt-10" style="font-family: monospace,monospace;">-Wanalyzer </span>tag (not to be confused with the GCC -W warning flags). The output includes Common
Weakness Enumeration (CWE) identifiers as well the ability to print a path of events that trigger the
flag.
</p>
<!-- l. 3 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.1   </span> <a id="x1-20001.1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>History of GCC-10 and GCC-11 Static Analyzers</h4>


<!-- l. 5 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">GCC-10 includes 15 <span class="ec-lmtt-10" style="font-family: monospace,monospace;">-fanalyzer </span>checkers: </p>


<ul class="itemize1">     
<li class="itemize"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">-Wanalyzer-double-free</span>
</li>     
<li class="itemize"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">-Wanalyzer-use-after-free</span>
</li>     
<li class="itemize"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">-Wanalyzer-free-of-non-heap</span>
</li>     
<li class="itemize"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">-Wanalyzer-malloc-leak</span>
</li>     
<li class="itemize"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">-Wanalyzer-possible-null-argument</span>
</li>     
<li class="itemize"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">-Wanalyzer-possible-null-dereference</span>
</li>     
<li class="itemize"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">-Wanalyzer-null-argument</span>
</li>     
<li class="itemize"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">-Wanalyzer-null-dereference</span>
</li>     
<li class="itemize"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">-Wanalyzer-double-fclose</span>
</li>     
<li class="itemize"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">-Wanalyzer-file-leak</span>
</li>     
<li class="itemize"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">-Wanalyzer-stale-setjmp-buffer</span>
</li>     
<li class="itemize"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">-Wanalyzer-use-of-pointer-in-stale-stack-frame</span>
</li>     
<li class="itemize"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">-Wanalyzer-unsafe-call-within-signal-handler</span>
</li>     
<li class="itemize"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">-Wanalyzer-tainted-array-index</span>
                                                                                         
                                                                                         
     
</li>
<li class="itemize"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">-Wanalyzer-exposure-through-output-file</span></li></ul>


<!-- l. 24 -->
<p class="indent" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   The checker works well on small to medium sized, C examples. An issue that Malcom noted includes bugs in the
analyzer’s state-tracking component regarding symbolic values and canonicalization to compare different states. As
these bugs were fixed, more bugs would be found. This prompted Malcom to rewrite the entire component for the
release of GCC-11.
</p>
<!-- l. 26 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   In the release of GCC-11, Malcom fixed the state-tracking component bugs by implementing the symbolic values
as singletons, using pointers and reducing large amounts of canonicalization code. Other features that Malcom
updated in this release include partial C++ support for <span class="ec-lmtt-10" style="font-family: monospace,monospace;">new </span>and <span class="ec-lmtt-10" style="font-family: monospace,monospace;">delete</span>, rewriting the memory leak detection to
generate fewer false positives, and fixing non-determinism logic to ensure that the analyzer’s behavior would not
vary from run to run.[<a href="#cite.0@20211220:gcc11" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">3</a>]
</p>
<!-- l. 28 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Additionally, GCC-11 adds 4 new <span class="ec-lmtt-10" style="font-family: monospace,monospace;">-fanalyzer </span>checkers: </p>


<ul class="itemize1">     
<li class="itemize"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">-Wanalyzer-write-to-const</span>
</li>     
<li class="itemize"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">-Wanalyzer-write-to-string-literal</span>
</li>     
<li class="itemize"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">-Wanalyzer-shift-count-negative</span>
</li>     
<li class="itemize"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">-Wanalyzer-shift-count-overflow</span></li></ul>


<!-- l. 36 -->
<p class="indent" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   The <span class="ec-lmtt-10" style="font-family: monospace,monospace;">-fanalyzer </span>flag can be directly added to the GCC command in terminal or to the CFLAGS variable for
Makefiles. Ensure that GCC warnings (-W warnings) are not disabled. Disabling warnings will also cause the
fanalyzer warnings to be suppressed. Malcolm is still developing the tool and we can look forward to new updates
and a large rewrite when GCC-12 is released.
</p>
<!-- l. 38 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.2   </span> <a id="x1-30001.2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Installing GCC-11 on Ubuntu-based Distributions</h4>


<!-- l. 40 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">This install is performed on a fresh install of Linux Mint 20.1 Cinnamon with some extra checks.
</p>
<!-- l. 42 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h5 class="subsubsectionHead"><span class="titlemark">1.2.1   </span> <a id="x1-40001.2.1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Update Apt Repository</h5>


<!-- l. 44 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">$ sudo apt update &amp;&amp; sudo apt upgrade</span>
</p>
<!-- l. 46 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   <span class="ec-lmtt-10" style="font-family: monospace,monospace;">update </span>will update the list of available packages and their versions while <span class="ec-lmtt-10" style="font-family: monospace,monospace;">upgrade </span>will install newer versions of
the packages you already have.
</p>
<!-- l. 48 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h5 class="subsubsectionHead"><span class="titlemark">1.2.2   </span> <a id="x1-50001.2.2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Check if GCC-11 is Already Installable</h5>


<!-- l. 50 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">$ apt-cache search gcc-11</span>
</p>
<!-- l. 52 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   <span class="ec-lmtt-10" style="font-family: monospace,monospace;">apt-cache </span>will display the gcc-11 packages if they are already installable from your current repositories. If you
see them, you can skip down to Section <a href="#x1-70001.2.4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1.2.4<!-- tex4ht:ref: sec:20211220:install  --></a> to install and configure.
                                                                                         
                                                                                         
</p>
<!-- l. 54 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h5 class="subsubsectionHead"><span class="titlemark">1.2.3   </span> <a id="x1-60001.2.3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Add Ubuntu Toolchain Repository</h5>


<!-- l. 56 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">$ add-apt-repository -y ppa:ubuntu-toolchain-r/test</span>
</p>
<!-- l. 58 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Newer versions of GCC and other development packages can be found in Ubuntu’s Toolchain test branch
PPA.
</p>
<!-- l. 60 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   If you receive the error <span class="ec-lmtt-10" style="font-family: monospace,monospace;">gpg: keyserver receive failed: general error</span>, you can manually pull down the
key from the error code with the following command:<br class="newline"/><span class="ec-lmtt-10" style="font-family: monospace,monospace;">$ sudo apt-key adv –keyserver keyserver.ubuntu.com –recv-key KEY_FROM_ERROR</span>
</p>
<!-- l. 63 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Don’t forget to run update again to update the list of available packages:<br class="newline"/><span class="ec-lmtt-10" style="font-family: monospace,monospace;">$ sudo apt update</span>
</p>
<!-- l. 66 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h5 class="subsubsectionHead"><span class="titlemark">1.2.4   </span> <a id="x1-70001.2.4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Installing and Configuring GCC</h5>


<!-- l. 69 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">$ sudo apt install gcc-11 &amp;&amp; sudo apt install g++-11</span>
</p>
<!-- l. 71 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   This is the general install command for GCC (with G++ support). To run, you can use gcc-11 when compiling,
or you can configure gcc to default to gcc-11 with the following command:<br class="newline"/><span class="ec-lmtt-10" style="font-family: monospace,monospace;">$ sudo update-alternatives –config gcc</span>
</p>
<!-- l. 74 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   This will allow you to make a selection based on the versions of gcc install. If you receive an error that there are
no alternatives, you can use the following few commands to add them manually:<br class="newline"/><span class="ec-lmtt-10" style="font-family: monospace,monospace;">$ sudo update-alternatives –remove-all gcc #To clean out</span><br class="newline"/><span class="ec-lmtt-10" style="font-family: monospace,monospace;">$ ls /usr/bin/gcc* #To see what versions you have installed</span><br class="newline"/><span class="ec-lmtt-10" style="font-family: monospace,monospace;">$ sudo update-alternatives –install /usr/bin/gcc gcc /usr/bin/gcc-11 10</span>
</p>
<!-- l. 79 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   The setup for the last command is <span class="ec-lmtt-10" style="font-family: monospace,monospace;">–install &lt;link&gt; &lt;name&gt; &lt;path&gt; &lt;priority&gt;</span>. Repeat the last command
for all versions of gcc listed.
                                                                                         
                                                                                         
</p>
   

<h3 class="sectionHead"><a id="x1-80001.2.4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>References</h3>


<!-- l. 49 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">    
</p>


<dl class="thebibliography"><dt id="X0-swatips" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[1]  
</dt><dd id="bib-1" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon Hood, ed. SwATips. <a href="https://www.SwATips.com/" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.SwATips.com/</span></a>.
</p>    
</dd>
<dt id="X0-20211220:gcc10" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[2]  
</dt><dd id="bib-2" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20211220:gcc10" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>David    Malcolm.    Static Analysis in GCC 10.    RedHat    Developer.    Mar. 26,    2020.    <span class="small-caps" style="font-variant: small-caps;">url</span>:
<a href="https://developers.redhat.com/blog/2020/03/26/static-analysis-in-gcc-10" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://developers.redhat.com/blog/2020/03/26/static-analysis-in-gcc-10</span></a>.
</p>    
</dd>
<dt id="X0-20211220:gcc11" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[3]  
</dt><dd id="bib-3" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20211220:gcc11" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>David   Malcolm.   Static Analysis Updates in GCC 11.   RedHat   Developer.   Jan. 28,   2021.   <span class="small-caps" style="font-variant: small-caps;">url</span>:
<a href="https://developers.redhat.com/blog/2021/01/28/static-analysis-updates-in-gcc-11" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://developers.redhat.com/blog/2021/01/28/static-analysis-updates-in-gcc-11</span></a>.</p></dd></dl>

 

]]></description>
	</item>
	<item>
		<title>Malicious Injection of Source Code</title>
		<link>https://www.SwATips.com/articles/20211129.html</link>
		<pubDate>Mon, 29 Nov 2021 00:00:00 -0600</pubDate>
<description><![CDATA[

<p style="margin-top: 0; margin-bottom: 0;"><a href="/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/swatips.svg" width="120" alt="SwATips" style="border-top: 0; border-left: 0; border-right: 0;"/></a>| <a href="articles/20211129.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">pdf</a> | <a rel="license" href="http://creativecommons.org/licenses/by/4.0/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/by.svg" width="60" height="21" alt="CC-BY" style="border-top: 0; border-left: 0; border-right: 0;"/></a></p>


<div class="maketitle" style="margin-top: 1em; text-align: center; margin-bottom: 2em;">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead" style="text-align: center;"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a href="#cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">3</a>]<br/>
</h2>
<div class="author" style="text-align: center;"><span class="rm-lmr-12" style="font-size: 120%;">Jon Hood</span></div><br/>
<div class="date" style="text-align: center;"><span class="rm-lmr-12" style="font-size: 120%;">Monday 29</span><sup class="textsuperscript"><span class="rm-lmr-9" style="font-size: 90%;">th</span></sup><span class="rm-lmr-12" style="font-size: 120%;"> November, 2021</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead"><span class="titlemark">1   </span> <a id="x1-10001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Malicious Injection of Source Code</h3>


<!-- l. 44 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;"><span class="rm-lmr-8" style="font-size: 80%;">Updated Monday 29</span><sup class="textsuperscript"><span class="rm-lmr-9" style="font-size: 90%;">th</span></sup><span class="rm-lmr-8" style="font-size: 80%;"> November, 2021</span>
</p>
<!-- l. 1 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Suppose that you are a spy, tasked with embedding a malicious backdoor into enemy source code. After being
hired onto the team, you find that every line of code is subject to manual code reviews. One of the best ways to hide
a Trojan is in plain sight: directly in the source code that’s being reviewed.
</p>
<!-- l. 3 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.1   </span> <a id="x1-20001.1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Unicode Injections</h4>


<!-- l. 4 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">One of my favorite types of attacks is the homoglyph attack.[<a href="#cite.0@20211129:hood" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2</a>] Developers can embed a function so deeply into code
with the apparent same name as a benign-looking version of the function. Consider the homoglyphs used in Boucher
and Anderson’s example in Figure <a href="#x1-2001r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1<!-- tex4ht:ref: lst:20211129:homoglyph  --></a>.[<a href="#cite.0@20211129:boucher" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1</a>] By using a Cyrillic <span class="ec-lmtt-10" style="font-family: monospace,monospace;">Н </span>and hiding the malicious <span class="ec-lmtt-10" style="font-family: monospace,monospace;">sayНello()</span>
deep into the code, the developers could be tricked into thinking that a different function is being
called.
</p>
   

<!-- l. 6 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-2001r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-2002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>
   

<div class="lstlisting" id="listing-1" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-2003r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">#include</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> &lt;iostream&gt; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-2004r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">void</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> sayHello() { </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-2005r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        std::cout &lt;&lt; "Hello, World!\n"; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-2006r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">} </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-2007r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">void</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> sayНello()</span><span class="rm-lmr-9" style="font-size: 90%;"> { </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-2008r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="rm-lmr-9" style="font-size: 90%;">        std::cout &lt;&lt; Goodbye, World!\n; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-2009r7" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="rm-lmr-9" style="font-size: 90%;">} </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-2010r8" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="rm-lmbx-9" style="font-size: 90%; font-weight: bold;">int</span><span class="rm-lmr-9" style="font-size: 90%;"> main() { </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-2011r9" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="rm-lmr-9" style="font-size: 90%;">        </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">sayНello()</span><span class="rm-lmr-9" style="font-size: 90%;">; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-2012r10" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="rm-lmr-9" style="font-size: 90%;">        </span><span class="rm-lmbx-9" style="font-size: 90%; font-weight: bold;">return</span><span class="rm-lmr-9" style="font-size: 90%;"> 0; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-2013r11" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="rm-lmr-9" style="font-size: 90%;">}</span>
<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 1:</span><span class="content">Homoglyphic Function</span></figcaption><!-- tex4ht:label?: x1-2001r1  -->
   
</div>


<!-- l. 20 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   But my favorite type of injection involves the use of bidirectional (BIDI) unicode symbols. Using these symbols,
the order of <i>display</i> can be changed from the order of <i>compiler evaluation</i>. Consider the function in Figure <a href="#x1-2014r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2<!-- tex4ht:ref: lst:20211129:comment  --></a>. While
functions or a return value may appear to be commented out on a web browser or development IDE, they are
actually part of the code and become a sneaky way to inject logic that appears commented out to a
reviewer.
</p>
   

<!-- l. 22 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-2014r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-2015" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>
   

<div class="lstlisting" id="listing-2" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-2016r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">#include</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> &lt;iostream&gt; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-2017r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-2018r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">bool isAdmin() </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-2019r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">{ </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-2020r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtti-10x-x-90" style="font-size: 90%; font-family: monospace,monospace; font-style: italic;">        /* If we are an admin, </span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">⁧</span><span class="ec-lmtti-10x-x-90" style="font-size: 90%; font-family: monospace,monospace; font-style: italic;"> /*/</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">return</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> true ; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-2021r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        std::cerr &lt;&lt; "You are not an admin." &lt;&lt; std::endl; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-2022r7" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">return</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> false; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-2023r8" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">} </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-2024r9" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-2025r10" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">int</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> main() </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-2026r11" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">{ </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-2027r12" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">if</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> (isAdmin()) </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-2028r13" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        { </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-2029r14" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">               std::cout &lt;&lt; "You are an admin." &lt;&lt; std::endl; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-2030r15" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        } </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-2031r16" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">else</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-2032r17" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        { </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-2033r18" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">               std::cout &lt;&lt; "You are NOT an admin." &lt;&lt; std::endl; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-2034r19" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        } </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-2035r20" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        </span><span class="ec-lmtk-10x-x-90" style="font-size: 90%; font-family: monospace,monospace;">return</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> 0; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-2036r21" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">}</span>
<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 2:</span><span class="content">Comment Reordering</span></figcaption><!-- tex4ht:label?: x1-2014r1  -->
   
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead"><a id="x1-30001.1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>References</h3>


<!-- l. 49 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">    
</p>


<dl class="thebibliography"><dt class="thebibliography" id="X0-20211129:boucher" style="float: left; clear: left; margin-right: 1em;">
[1]  
</dt><dd class="thebibliography" id="bib-1" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20211129:boucher" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Nicholas Boucher and Ross Anderson. “Trojan Source: Invisible Vulnerabilities”. In: Preprint (2021).
arXiv: <a href="https://arxiv.org/abs/2111.00169" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">2111.00169 [cs.CR]</span></a>. <span class="small-caps" style="font-variant: small-caps;">url</span>: <a href="https://arxiv.org/abs/2111.00169" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://arxiv.org/abs/2111.00169</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-20211129:hood" style="float: left; clear: left; margin-right: 1em;">
[2]  
</dt><dd class="thebibliography" id="bib-2" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20211129:hood" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon    Hood.    “Homoglyphs    and    Homographic    Attacks”.    In:    SwATips.com    (2021).    <span class="small-caps" style="font-variant: small-caps;">url</span>:
<a href="https://www.swatips.com/articles/20210510.html" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.swatips.com/articles/20210510.html</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-swatips" style="float: left; clear: left; margin-right: 1em;">
[3]  
</dt><dd class="thebibliography" id="bib-3" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon Hood, ed. SwATips. <a href="https://www.SwATips.com/" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.SwATips.com/</span></a>.</p></dd></dl>

 

]]></description>
	</item>
	<item>
		<title>Additional Risks to DevSecOps Pipelines</title>
		<link>https://www.SwATips.com/articles/20211101.html</link>
		<pubDate>Mon, 01 Nov 2021 00:00:00 -0500</pubDate>
<description><![CDATA[

<p style="margin-top: 0; margin-bottom: 0;"><a href="/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/swatips.svg" width="120" alt="SwATips" style="border-top: 0; border-left: 0; border-right: 0;"/></a>| <a href="articles/20211101.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">pdf</a> | <a rel="license" href="http://creativecommons.org/licenses/by/4.0/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/by.svg" width="60" height="21" alt="CC-BY" style="border-top: 0; border-left: 0; border-right: 0;"/></a></p>


<div class="maketitle" style="margin-top: 1em; text-align: center; margin-bottom: 2em;">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead" style="text-align: center;"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a href="#cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1</a>]<br/>
</h2>
<div class="author" style="text-align: center;"><span class="rm-lmr-12" style="font-size: 120%;">Jon Hood</span></div><br/>
<div class="date" style="text-align: center;"><span class="rm-lmr-12" style="font-size: 120%;">Monday 1</span><sup class="textsuperscript"><span class="rm-lmr-9" style="font-size: 90%;">st</span></sup><span class="rm-lmr-12" style="font-size: 120%;"> November, 2021</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead"><span class="titlemark">1   </span> <a id="x1-10001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Additional Risks to DevSecOps Pipelines</h3>


<!-- l. 44 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;"><span class="rm-lmr-8" style="font-size: 80%;">Updated Monday 1</span><sup class="textsuperscript"><span class="rm-lmr-9" style="font-size: 90%;">st</span></sup><span class="rm-lmr-8" style="font-size: 80%;"> November, 2021</span>
</p>
<!-- l. 1 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   I remain a huge fan of DevSecOps pipelines. The benefit to including automated security scans and checks into
the development lifecycle fosters a culture of security. Alerting developers to bad habits and patterns early in the
development process is one of the best ways to avoid costly reprogramming efforts in the future. Nevertheless, the
upsides of DevSecOps pipelines should not cause someone to overlook the additional risks and attack vectors
introduced by implementing such processes.
</p>
<!-- l. 3 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.1   </span> <a id="x1-20001.1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Increased Attack Area</h4>


<!-- l. 4 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Additional software, management hooks, and authenticated entities are needed to set up an automated DevSecOps
pipeline. The goal is to secure this pipeline so that a level of confidence and assurance in the products that
come out of it can be achieved. Yet the authentication to build servers, scan servers, fuzzing engines,
code coverage algorithms, and whatever else is being used to help secure the code each come with a
new attack vector. Automation scripts can be harvested to glean credentials. Rules can be added and
modified to evade detection. And each additional tool added to the networked automation must be
maintained.
</p>
<!-- l. 6 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Our current SOP for non-DevSecOps environments is to perform scans entirely offline. This prevents the
scanning tools themselves, binaries being dynamically analyzed, and scripts being interpreted from phoning home.
This is not always a possible step to take in a fully connected DevSecOps environment. Furthermore, it’s rare for
each development shop to set up individual authenticators for each program in their pipeline. Suppose that one of
the projects in an organization give access to an outside entity to change third-party code in a section of their
repository. Assuming that this third-party repository is also configured for scanning, any vulnerabilities or
misconfigurations of the scan tools can expose code that is not part of that external organization’s
repository.
</p>
<!-- l. 8 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   The biggest risk of combining each program into a single DevSecOps process is giving the keys of the
kingdom—the entirety of every project’s code and build process—to the administrators that maintain the
DevSecOps environment. Handing off this responsibility instead of keeping it disparate means that a
single compromise to your DevSecOps management credentials gives an attacker access to your entire
kingdom.
</p>
<!-- l. 10 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.2   </span> <a id="x1-30001.2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Accepting the Risk</h4>


<!-- l. 11 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Are you working on projects that have a high level of secrecy? Is the additional cost of setting up your own pipeline
for this particular project worth it so that exposures on a centralized DevSecOps environment do not impact your
program’s security? Do you trust the tools being used in your agile supply chain? If you’re considering a
centralized DevSecOps environment for your organization, these are serious questions that must be
answered.
</p>
<!-- l. 13 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Praising the benefits of a centralized DevSecOps pipeline should not be interpreted as overlooking the additional
security concerns it can introduce. Consider the code coverage tool, Codecov. Earlier this year, one of their
uploading mechanisms was compromised in a discreet way that exposed hundreds of credentials (including this
author’s).[<a href="#cite.0@20211101:sharma2021" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2</a>] For more than two months, attackers passively intercepted the credentials of Codecov users, including
tokens that authenticated to more repositories than just the ones using Codecov. When developers work to
build test cases, code coverage statistics, and automated scanning in a DevSecOps environment, it
stings a little bit more when the tools that are used to secure the pipeline are the ones that become
compromised.
                                                                                         
                                                                                         
</p>
   

<h3 class="sectionHead"><a id="x1-40001.2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>References</h3>


<!-- l. 49 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">    
</p>


<dl class="thebibliography"><dt id="X0-swatips" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[1]  
</dt><dd id="bib-1" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon Hood, ed. SwATips. <a href="https://www.SwATips.com/" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.SwATips.com/</span></a>.
</p>    
</dd>
<dt id="X0-20211101:sharma2021" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[2]  
</dt><dd id="bib-2" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20211101:sharma2021" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Ax Sharma. Codecov hack aftermath. hundreds breached, many more to follow. Security Report. Apr. 27,
2011. <span class="small-caps" style="font-variant: small-caps;">url</span>: <a href="https://securityreport.com/codecov-hack-aftermath-hundreds-breached-many-more-to-follow/" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://securityreport.com/codecov-hack-aftermath-hundreds-breached-many-more-to-follow/</span></a>
(visited on 11/01/2021).</p></dd></dl>

 

]]></description>
	</item>
	<item>
		<title>Perls of Wisdom</title>
		<link>https://www.SwATips.com/articles/20211004.html</link>
		<pubDate>Mon, 04 Oct 2021 00:00:00 -0500</pubDate>
<description><![CDATA[

<p style="margin-top: 0; margin-bottom: 0;"><a href="/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/swatips.svg" width="120" alt="SwATips" style="border-top: 0; border-left: 0; border-right: 0;"/></a>| <a href="articles/20211004.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">pdf</a> | <a rel="license" href="http://creativecommons.org/licenses/by/4.0/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/by.svg" width="60" height="21" alt="CC-BY" style="border-top: 0; border-left: 0; border-right: 0;"/></a></p>


<div class="maketitle" style="margin-top: 1em; text-align: center; margin-bottom: 2em;">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead" style="text-align: center;"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a href="#cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2</a>]<br/>
</h2>
<div class="author" style="text-align: center;"><span class="rm-lmr-12" style="font-size: 120%;">Kevin Keen</span></div><br/>
<div class="date" style="text-align: center;"><span class="rm-lmr-12" style="font-size: 120%;">Monday 4</span><sup class="textsuperscript"><span class="rm-lmr-9" style="font-size: 90%;">th</span></sup><span class="rm-lmr-12" style="font-size: 120%;"> October, 2021</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead"><span class="titlemark">1   </span> <a id="x1-10001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Perls of Wisdom</h3>


<!-- l. 44 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;"><span class="rm-lmr-8" style="font-size: 80%;">Updated Monday 4</span><sup class="textsuperscript"><span class="rm-lmr-9" style="font-size: 90%;">th</span></sup><span class="rm-lmr-8" style="font-size: 80%;"> October, 2021</span>
</p>
<!-- l. 1 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   We see far less Perl code than some other languages. Nevertheless, as with any language, there are security
concerns that are particular to Perl.
</p>
<!-- l. 3 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Consider the following short Perl script in Listing <a href="#x1-1001r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1<!-- tex4ht:ref: lst:20211004:script  --></a>.
</p>
   

<!-- l. 5 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-1001r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-1002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>
   

<div class="lstlisting" id="listing-1" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-1003r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">my</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> $in_filename; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1004r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">my</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> $out_filename; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1005r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">if</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">(</span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">scalar</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> @ARGV &lt; 1) { </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1006r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">       </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">print</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> "Usage: $0 &lt;input_file&gt;"; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1007r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">       </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">exit</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1008r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">} </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1009r7" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">else</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> { </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1010r8" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">       $in_filename = $ARGV[0]; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1011r9" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">       $out_filename = "that_$in_filename"; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1012r10" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">} </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1013r11" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">open</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">($in_file, "$in_filename"); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1014r12" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">open</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">($out_file, "&gt;$out_filename"); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1015r13" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">while</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">(&lt;$in_file&gt;) { </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1016r14" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">       $line = $_; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1017r15" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">       </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">print</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> "$line"; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1018r16" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">       </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">if</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> ($line =~ /This is a/) { </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1019r17" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">               $line =~ </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">s</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">/This is a/That is a/; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1020r18" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">               </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">print</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> "First Match!\n"; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1021r19" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">       } </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1022r20" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">       </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">elsif</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">($line =~ /This is only/) { </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1023r21" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">               $line =~ </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">s</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">/This is only/That is only/; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1024r22" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">               </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">print</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> "Second Match!\n"; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1025r23" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">       } </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1026r24" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">       </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">print</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> $out_file $line; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1027r25" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">}</span>
<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 1:</span><span class="content">Sample Perl Script</span></figcaption><!-- tex4ht:label?: x1-1001r1  -->
   
</div>


<!-- l. 33 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   This script will read in the input file, perform some substitutions (changing “This” to “That”)
and write out the results to another file. With Perl’s deeply ingrained regex facilities, such string and
file processing is very typical of a Perl script. The input file name is passed in as a command line
argument. The output filename is derived by prepending <span class="ec-lmtt-10" style="font-family: monospace,monospace;">that_</span>. As with a lot of Perl scripts, this one is
written to be run against input files with very specific contents. In this case, it expects the input file to
contain the input displayed in Listing <a href="#x1-1028r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2<!-- tex4ht:ref: lst:20211004:input  --></a>. The output of the intended use of this script is shown in
Listing <a href="#x1-1032r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">3<!-- tex4ht:ref: lst:20211004:goodoutput  --></a>.
</p>
   

<!-- l. 35 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-1028r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-1029" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>
   

<div class="lstlisting" id="listing-2" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-1030r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">This is a </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">test</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1031r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">This is only a </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">test</span>
<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 2:</span><span class="content">Sample Input</span></figcaption><!-- tex4ht:label?: x1-1028r1  -->
   
</div>


<!-- l. 40 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-1032r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-1033" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>
   

<div class="lstlisting" id="listing-3" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-1034r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">$ ls </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1035r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">textfile  this_to_that.pl </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1036r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1037r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">$ </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">cat</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> textfile </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1038r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">This is a </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">test</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1039r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">This is only a </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">test</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1040r7" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1041r8" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">$ perl this_to_that.pl textfile </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1042r9" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">This is a </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">test</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1043r10" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">First Match! </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1044r11" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">This is only a </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">test</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1045r12" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">Second Match! </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1046r13" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1047r14" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">$ </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">cat</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> that_textfile </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1048r15" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">That is a </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">test</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1049r16" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">That is only a </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">test</span>
<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 3:</span><span class="content">Sample Execution</span></figcaption><!-- tex4ht:label?: x1-1032r1  -->
   
</div>


<!-- l. 59 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   The biggest security concern here comes from the use of the two argument form of open, which in some
cases, can actually result in shell execution! Contained in the two open statements shown in the above
source, you will notice that one filename is prefixed with “¿”, but the first open has no prefix. The
“¿” character on the second open tells Perl to open the file for output. The first open is implicitly
open for input. This doesn’t look bad just looking at the source, but Perl has built-in magic that
makes this a security disaster. In this kind of case, if the filename starts with, or ends with a pipe
symbol (<span class="ec-lmtt-10" style="font-family: monospace,monospace;">|</span>), Perl interprets that as requesting execution of a shell command. Note that the location
of the pipe symbol also has meaning to Perl. A pipe symbol before the command indicates a shell
command that should be written to. A pipe symbol after the command indicates a shell command that
should be read from. This means that abusing this form of open is as easy as providing a malicious
filename.
</p>
   

<!-- l. 61 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-1050r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-1051" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>

                                                                                         
                                                                                         
   

<div class="lstlisting" id="listing-4" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-1052r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">$ ls </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1053r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">textfile  this_to_that.pl </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1054r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1055r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">$ perl this_to_that.pl "touch in_a_shell_command|" </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1056r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1057r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">$ ls </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1058r7" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> in_a_shell_command  </span><span class="ts1-lmtt10-">'</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">that_touch␣in_a_shell_command|</span><span class="ts1-lmtt10-">'</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1059r8" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> textfile            this_to_that.pl</span>
<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 4:</span><span class="content">Malicious Execution</span></figcaption><!-- tex4ht:label?: x1-1050r1  -->
   
</div>


<!-- l. 72 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Listing <a href="#x1-1050r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">4<!-- tex4ht:ref: lst:20211004:badoutput  --></a> shows the result of running the script with a malicious filename resulting in the file “im_a_shell_cmd”
being created. The other new file, “that_touch im_a_shell_cmd—”, is created by the script as part of its normal
output. Of course in this case we already had shell access, but consider the case where the filename is coming from
an external attack such a socket or web interface.
</p>
<!-- l. 74 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   This security disaster can be partially mitigated by explicitly specifying that the file should be open for input. If
a leading “¡” is provided (similar to the second open statement), Perl will assume the filename is just a filename even
if a pipe symbol appears. If all of that were not enough, this version of open can cause problems when we can’t
even see it because a number of other constructs use the two argument version of open behind the
scenes. The examples in Listing <a href="#x1-1060r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">5<!-- tex4ht:ref: lst:20211004:examples  --></a> are all implicitly using the two argument form of open.[<a href="#cite.0@20211004:svoboda" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">3</a>] Such
constructs should be avoided, and the 3 argument form of open used instead of the two argument
version.[<a href="#cite.0@20211004:dimov" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1</a>]
</p>
   

<!-- l. 76 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-1060r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-1061" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>
   

<div class="lstlisting" id="listing-5" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-1062r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">while</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">(&lt;ARGV&gt;) </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1063r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">while</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">(&lt;&gt;) </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1064r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">perl -n </span><span class="ts1-lmtt10-">'</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">print␣"::␣$_\n";</span><span class="ts1-lmtt10-">'</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> * </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-1065r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">perl -p </span><span class="ts1-lmtt10-">'</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">$_␣=␣"::␣$_\n";</span><span class="ts1-lmtt10-">'</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> *</span>
<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 5:</span><span class="content">Examples</span></figcaption><!-- tex4ht:label?: x1-1060r1  -->
   
</div>


<!-- l. 84 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.1   </span> <a id="x1-20001.1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Bonus Tip</h4>


<!-- l. 85 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Using “¡” or “¿” on the two argument form of open is not enough to solve the woes of using it because Perl has even
more magic up its sleeve. A filename of dash is interpreted to mean STDIN. Although explicitly providing the input
mode character “¡” avoids the command injection, we still have a very viable denial of service. Often, a string is
concatenated before being passed to open. One question that arises is “when will dash be considered to be
STDIN”. Both with and without the explicit “¡” symbol, both –, and “-“, as a command line argument
is interpreted by Perl to mean STDIN. But what of the case where dash is concatenated? It seems
backwards, but when the explicit “¡” character is <strong>not</strong> provided, “- something” is not interpreted to
mean STDIN. However, when “¡” <strong>IS</strong> provided the same input will result in an attempt to read from
STDIN.
                                                                                         
                                                                                         
</p>
   

<h3 class="sectionHead"><a id="x1-30001.1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>References</h3>


<!-- l. 49 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">    
</p>


<dl class="thebibliography"><dt class="thebibliography" id="X0-20211004:dimov" style="float: left; clear: left; margin-right: 1em;">
[1]  
</dt><dd class="thebibliography" id="bib-1" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20211004:dimov" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jordan Dimov. Security Issues in Perl Scripts. <span class="small-caps" style="font-variant: small-caps;">url</span>: <a class="url" href="https://www.cgisecurity.com/lib/sips.html" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.cgisecurity.com/lib/sips.html</span></a>
(visited on 10/04/2021).
</p>    
</dd>
<dt class="thebibliography" id="X0-swatips" style="float: left; clear: left; margin-right: 1em;">
[2]  
</dt><dd class="thebibliography" id="bib-2" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon Hood, ed. SwATips. <a class="url" href="https://www.SwATips.com/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.SwATips.com/</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-20211004:svoboda" style="float: left; clear: left; margin-right: 1em;">
[3]  
</dt><dd class="thebibliography" id="bib-3" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20211004:svoboda" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>David      Svoboda.      IDS31-PL. Do not use the two-argument form of open().      Nov. 16,      2017.
<span class="small-caps" style="font-variant: small-caps;">url</span>:  <a class="url" href="https://wiki.sei.cmu.edu/confluence/pages/viewpage.action?pageId=88890543" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://wiki.sei.cmu.edu/confluence/pages/viewpage.action?pageId=88890543</span></a> (visited
on 10/04/2021).</p></dd></dl>

 

]]></description>
	</item>
	<item>
		<title>Static Header Paths</title>
		<link>https://www.SwATips.com/articles/20210913.html</link>
		<pubDate>Mon, 13 Sep 2021 00:00:00 -0500</pubDate>
<description><![CDATA[

<p style="margin-top: 0; margin-bottom: 0;"><a href="/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/swatips.svg" width="120" alt="SwATips" style="border-top: 0; border-left: 0; border-right: 0;"/></a>| <a href="articles/20210913.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">pdf</a> | <a rel="license" href="http://creativecommons.org/licenses/by/4.0/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/by.svg" width="60" height="21" alt="CC-BY" style="border-top: 0; border-left: 0; border-right: 0;"/></a></p>


<div class="maketitle" style="margin-top: 1em; text-align: center; margin-bottom: 2em;">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead" style="text-align: center;"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a href="#cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2</a>]<br/>
</h2>
<div class="author" style="text-align: center;"><span class="rm-lmr-12" style="font-size: 120%;">Jon Hood</span></div><br/>
<div class="date" style="text-align: center;"><span class="rm-lmr-12" style="font-size: 120%;">Monday 13</span><sup class="textsuperscript"><span class="rm-lmr-9" style="font-size: 90%;">th</span></sup><span class="rm-lmr-12" style="font-size: 120%;"> September, 2021</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead"><span class="titlemark">1   </span> <a id="x1-10001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Static Header Paths</h3>


<!-- l. 43 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;"><span class="rm-lmr-8" style="font-size: 80%;">Updated Monday 13</span><sup class="textsuperscript"><span class="rm-lmr-9" style="font-size: 90%;">th</span></sup><span class="rm-lmr-8" style="font-size: 80%;"> September, 2021</span>
</p>
<!-- l. 1 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   While manually reviewing some VxWorks-based code, I noticed that a developer had included a header file from
the VxWorks library in an odd way. The entire path to the header file is present in the include directive as shown in
Listing <a href="#x1-1001r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1<!-- tex4ht:ref: lst:20210913:path  --></a>.
</p>
   

<!-- l. 3 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-1001r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-1002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>
   

<div id="listing-1" class="lstlisting" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-1003r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">#include</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> &lt;C:\VxWorks-Headers-version\path\to\staticdefinitions.h&gt;</span>
<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 1:</span><span class="content">Include Directive</span></figcaption><!-- tex4ht:label?: x1-1001r1  -->
   
</div>


<!-- l. 7 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Static paths inside of source code, particularly in the headers, can cause several issues.
</p>
<!-- l. 9 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   First, the code can only be compiled on an OS That understands the path directives. Non-ubiquitous code is
flagged, particularly when the software itself is written to support any platform within the VxWorks portfolio.[<a href="#cite.0@20210913:cwe-589" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1</a>]
Note that the C99 standard allows <span class="ec-lmtt-10" style="font-family: monospace,monospace;">#include </span>directives with \ as a directory separator when it’s between either
&lt;&gt; or “”.
</p>
<!-- l. 11 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Second, the VxWorks-Headers-version folder is not maintained in version control. It is part of the build
environment, but that environment has several different versions of VxWorks updates installed. An update
to VxWorks means that the code files themselves have to be updated to support the new VxWorks
version.
</p>
<!-- l. 13 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Finally, the VxWorks libraries are installed with any-user privileges that allow an attacker with access to the
build environment to inject code into the header file in a way that avoids the scan tools being used. Since the
potentially injected code is never a apart of the code repository, it avoids peer review, scrutiny, and change
management.
</p>
<!-- l. 15 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Attacking the build environment of a product is one of the sneakiest ways to inject malicious software into it.
Developers who rely on external code should verify that it’s trusted, under change management, and scanned as part
of their solution.
                                                                                         
                                                                                         
</p>
   

<h3 class="sectionHead"><a id="x1-20001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>References</h3>


<!-- l. 48 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">    
</p>


<dl class="thebibliography"><dt id="X0-20210913:cwe-589" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[1]  
</dt><dd id="bib-1" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 48 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20210913:cwe-589" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>CWE    Content    Team.    “CWE-589:    Call    to    Non-ubiquitous    API”.    In:    (2021).    <span class="small-caps" style="font-variant: small-caps;">url</span>:
<a class="url" href="https://cwe.mitre.org/data/definitions/589.html" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://cwe.mitre.org/data/definitions/589.html</span></a>.
</p>    
</dd>
<dt id="X0-swatips" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[2]  
</dt><dd id="bib-2" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 48 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon Hood, ed. SwATips. <a class="url" href="https://www.SwATips.com/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.SwATips.com/</span></a>.</p></dd></dl>

 

]]></description>
	</item>
	<item>
		<title>When Code Analysis Fails</title>
		<link>https://www.SwATips.com/articles/20210906.html</link>
		<pubDate>Mon, 06 Sep 2021 00:00:00 -0500</pubDate>
<description><![CDATA[

<p style="margin-top: 0; margin-bottom: 0;"><a href="/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/swatips.svg" width="120" alt="SwATips" style="border-top: 0; border-left: 0; border-right: 0;"/></a>| <a href="articles/20210906.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">pdf</a> | <a rel="license" href="http://creativecommons.org/licenses/by/4.0/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/by.svg" width="60" height="21" alt="CC-BY" style="border-top: 0; border-left: 0; border-right: 0;"/></a></p>


<div class="maketitle" style="margin-top: 1em; text-align: center; margin-bottom: 2em;">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead" style="text-align: center;"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a href="#cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1</a>]<br/>
</h2>
<div class="author" style="text-align: center;"><span class="rm-lmr-12" style="font-size: 120%;">Jon Hood</span></div><br/>
<div class="date" style="text-align: center;"><span class="rm-lmr-12" style="font-size: 120%;">Monday 6</span><sup class="textsuperscript"><span class="rm-lmr-9" style="font-size: 90%;">th</span></sup><span class="rm-lmr-12" style="font-size: 120%;"> September, 2021</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead"><span class="titlemark">1   </span> <a id="x1-10001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>When Code Analysis Fails</h3>


<!-- l. 43 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;"><span class="rm-lmr-8" style="font-size: 80%;">Updated Monday 6</span><sup class="textsuperscript"><span class="rm-lmr-9" style="font-size: 90%;">th</span></sup><span class="rm-lmr-8" style="font-size: 80%;"> September, 2021</span>
</p>
<!-- l. 1 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   <i>This article contains content that originally appeared in the August 31, 2017 Software Assurance
Tips</i>
</p>
<!-- l. 3 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   One of the first open source projects I ever made was a webpage visit counter. But this was no ordinary counter:
a user could upload a picture, and the code would overlay the webpage “hits” on that picture. The project was
hosted on an old Compaq 133MHz 4U rackmount server that a friend and I “purchased” (i.e., rescued from the
dumpster), installed Linux+Apache+PHP on, and connected to his state-of-the-art Cable Alabama broadband
connection. The code used ImageMagick to dynamically rebuild the image every time a request came in to show the
picture and the number of hits.
</p>
<!-- l. 5 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Everything worked great…until we started getting several hundred hits per second! The server could not keep up
with the request load, and during peak usage, it was practically inaccessible. I learned an important lesson in
resource management!
</p>
<!-- l. 7 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Now that development projects are more security-aware, our SwA team would identify any unsanitized image
coming from the user as a potential for code injection, resource management errors, or even a steganography attack.
Nevertheless, software sometimes has the requirement of accepting images from users. Using an up-to-date image
processing library and limiting the types of input that can be received are critical for managing a system’s
resources.
</p>
<!-- l. 9 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Recently, we’ve evaluated some image and map manipulation software that draws pictures and graphs on the
supplied images. The systems were marked for not using an up-to-date version of their graphics manipulation
software. Suppose that developers decide to implement GraphicsMagick (<a href="http://www.graphicsmagick.org/" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">http://www.graphicsmagick.org/</span></a>) as
their graphics manipulation library. The software advertises a maintainable codebase (even mentioning the famous
David A. Wheeler on their main page) and that their recent Coverity scans reveal 0 defects per 1000 lines of code.
With credentials like that, it can’t be insecure! Nevertheless, CVE-2017-13777 is out detailing a resource
consumption attack with XBM (bitmap) images.[<a href="#cite.0@20210906:CVE-2017-13777" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2</a>] A pernicious bitmap would have brought my old server to a
halt!
</p>
<!-- l. 11 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Even if the security scans don’t find an issue, we continue to mark references to unmaintained versions of
software as a potential security concern. It indicates that a development team is not staying up-to-date with the
latest dependency developments and may miss important CVEs and security-relevant software updates.
CVE-2017-13777 is a prime example of what happens when precautionary software assurance techniques don’t
identify an underlying issue in the code. If someone were to take the Juliet SARD test suite and run it
against an analysis tool, it is very likely that the tool would not identify the flaw in more than 50%
of the examples. Therefore, a competent software assurance plan does not merely take a proactive,
preventative approach to software security; it must also have a reactionary, continuing plan for software
maintenance.
                                                                                         
                                                                                         
</p>
   

<h3 class="sectionHead"><a id="x1-20001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>References</h3>


<!-- l. 48 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">    
</p>


<dl class="thebibliography"><dt class="thebibliography" id="X0-swatips" style="float: left; clear: left; margin-right: 1em;">
[1]  
</dt><dd class="thebibliography" id="bib-1" style="margin-left: 2.5em;">
<!-- l. 48 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon Hood, ed. SwATips. <a href="https://www.SwATips.com/" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.SwATips.com/</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-20210906:CVE-2017-13777" style="float: left; clear: left; margin-right: 1em;">
[2]  
</dt><dd class="thebibliography" id="bib-2" style="margin-left: 2.5em;">
<!-- l. 48 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20210906:CVE-2017-13777" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>MITRE.                    CVE-2017-13777.                    Aug.                    2017.                    <span class="small-caps" style="font-variant: small-caps;">url</span>:
<a href="http://cve.mitre.org/cgi-bin/cvename.cgi?name=CVE-2017-13777" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">http://cve.mitre.org/cgi-bin/cvename.cgi?name=CVE-2017-13777</span></a>.</p></dd></dl>

 

]]></description>
	</item>
	<item>
		<title>A CWE-499 Breakdown: Serializing Sensitive Data</title>
		<link>https://www.SwATips.com/articles/20210830.html</link>
		<pubDate>Mon, 30 Aug 2021 00:00:00 -0500</pubDate>
<description><![CDATA[

<p style="margin-top: 0; margin-bottom: 0;"><a href="/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/swatips.svg" width="120" alt="SwATips" style="border-top: 0; border-left: 0; border-right: 0;"/></a> | <a href="articles/20210830.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">pdf</a> | <a rel="license" href="http://creativecommons.org/licenses/by/4.0/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/by.svg" width="60" height="21" alt="CC-BY" style="border-top: 0; border-left: 0; border-right: 0;"/></a></p>


<div class="maketitle" style="margin-top: 1em; text-align: center; margin-bottom: 2em;">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead" style="text-align: center;"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a href="#cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">3</a>]<br/>
</h2>
<div class="author" style="text-align: center;"><span class="rm-lmr-12" style="font-size: 120%;">Chris Ramsey</span></div><br/>
<div class="date" style="text-align: center;"><span class="rm-lmr-12" style="font-size: 120%;">Monday 30</span><sup class="textsuperscript"><span class="rm-lmr-9" style="font-size: 90%;">th</span></sup><span class="rm-lmr-12" style="font-size: 120%;"> August, 2021</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead"><span class="titlemark">1   </span> <a id="x1-10001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>A CWE-499 Breakdown: Serializing Sensitive Data</h3>


<!-- l. 43 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;"><span class="rm-lmr-8" style="font-size: 80%;">Updated Monday 30</span><sup class="textsuperscript"><span class="rm-lmr-9" style="font-size: 90%;">th</span></sup><span class="rm-lmr-8" style="font-size: 80%;"> August, 2021</span>
</p>
<!-- l. 1 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Recently, we detected a potential CWE-499 on some of the source being scanned in the lab. It raised some
questions and debate among us, and left me scratching my head. Being a curious fellow, I took it upon myself to
play around with it to try to figure it out. I’m not a Java developer by any stretch of the imagination, but I am a
certified security professional with a background in software development. So, with a fresh install of Eclipse, I went
to work.
</p>
<!-- l. 3 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.1   </span> <a id="x1-20001.1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>The CWE</h4>


<!-- l. 4 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Below, you can see the summary and description of this CWE:
</p>
     

<blockquote class="quote">
<!-- l. 6 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><strong>CWE-499: Serializable Class Containing Sensitive Data</strong>
</p>     
<!-- l. 8 --><p class="noindent" style="margin-bottom: 0; margin-top: 1em;"><span class="paragraphHead" style="margin-top: 2em; font-weight: bold;"><a id="x1-30001.1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><span class="rm-lmbx-10" style="font-weight: bold;">Description</span></span>
 <br class="newline"/>The code contains a class with sensitive data, but the class does not explicitly deny serialization. The
data can be accessed by serializing the class through another class.
</p>     
<!-- l. 11 --><p class="noindent" style="margin-bottom: 0; margin-top: 1em;"><span class="paragraphHead" style="margin-top: 2em; font-weight: bold;"><a id="x1-40001.1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><span class="rm-lmbx-10" style="font-weight: bold;">Extended Description</span></span>
 <br class="newline"/>Serializable classes are effectively open classes since data cannot be hidden in them. Classes that do not
explicitly deny serialization can be serialized by any other class, which can then in turn use the data
stored inside it.
</p>     
<!-- l. 14 --><p class="noindent" style="margin-bottom: 0; margin-top: 1em;"><span class="paragraphHead" style="margin-top: 2em; font-weight: bold;"><a id="x1-50001.1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><span class="rm-lmbx-10" style="font-weight: bold;">Applicable Languages</span></span>
 <br class="newline"/>Java (Undetermined Prevalence)
</p>     
<!-- l. 17 --><p class="noindent" style="margin-bottom: 0; margin-top: 1em;"><span class="paragraphHead" style="margin-top: 2em; font-weight: bold;"><a id="x1-60001.1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><span class="rm-lmbx-10" style="font-weight: bold;">Demonstrative Example</span></span>
 <br class="newline"/></p><!-- l. 18 -->
<a id="x1-6001r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>
<a id="x1-6002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>
<div id="listing-1" class="lstlisting" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-6003r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">class</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> PatientRecord { </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-6004r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">       </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">private</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> String name; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-6005r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">       </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">private</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> String socialSecurityNum; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-6006r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">       </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">public</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> Patient(String name,String ssn) { </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-6007r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">               </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">this</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">.SetName(name); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-6008r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">               </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">this</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">.SetSocialSecurityNumber(ssn); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-6009r7" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">       } </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-6010r8" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">}</span>
<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 1:</span><span class="content">Example 1</span></figcaption><!-- tex4ht:label?: x1-6001r1  -->
                                                                                         
                                                                                         
     
</div>
<!-- l. 27 --><p class="noindent" style="margin-bottom: 0; margin-top: 1em;">[<a href="#cite.0@20210830:cwe-499" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2</a>]</p></blockquote>


<!-- l. 30 -->
<p class="indent" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   Did I read that right? Sensitive data contained within a class that doesn’t explicitly deny serialization can be
accessed by serializing the class through another class‽ This, I’ve got to see.
</p>
<!-- l. 32 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.2   </span> <a id="x1-70001.2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>ClassA—Sensitive Data Container</h4>


<!-- l. 33 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">So, let’s start with a simple class that contains some sensitive data. Duplicating the example from the CWE should
suffice. </p>
<!-- l. 34 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-7001r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-7002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>
   

<div id="listing-2" class="lstlisting" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-7003r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">package</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> swa; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-7004r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">public</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">class</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> ClassA { </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-7005r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">       </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">private</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> String name; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-7006r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">       </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">private</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> String socialSecurityNum; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-7007r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">       </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">public</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> ClassA(String name,String ssn) { </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-7008r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">               </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">this</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">.SetName(name); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-7009r7" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">               </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">this</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">.SetSocialSecurityNumber(ssn); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-7010r8" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">       } </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-7011r9" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">}</span>
<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 2:</span><span class="content">ClassA</span></figcaption><!-- tex4ht:label?: x1-7001r1  -->
   
</div>


<!-- l. 46 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Given this is meant to be a container of sensitive data, I didn’t make the class in Listing <a href="#x1-7001r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2<!-- tex4ht:ref: lst:20210830:classa  --></a> serializable. Let’s
create a serializable wrapper around it and see if we can get at the data.
</p>
<!-- l. 48 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.3   </span> <a id="x1-80001.3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>ClassB—Serializable Wrapper</h4>


<!-- l. 50 -->


<p style="margin-top: 0; margin-bottom: 0;"><a id="x1-8001r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-8002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>
   

<div id="listing-3" class="lstlisting" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-8003r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">package</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> swa; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-8004r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">import</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> java.io.Serializable; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-8005r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">public</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">class</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> ClassB </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">implements</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> Serializable { </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-8006r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">       </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">private</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">static</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">final</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">long</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> serialVersionUID = 1L; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-8007r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">       ClassA obj; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-8008r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">       </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">public</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;"> ClassB(ClassA objVal) { </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-8009r7" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">               </span><span class="ec-lmtk-10" style="font-family: monospace,monospace;">this</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">.obj = objVal; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-8010r8" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">       } </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-8011r9" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">}</span>
<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 3:</span><span class="content">ClassB</span></figcaption><!-- tex4ht:label?: x1-8001r1  -->
   
</div>


<!-- l. 62 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Listing <a href="#x1-8001r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">3<!-- tex4ht:ref: lst:20210830:classb  --></a> demonstrates a serializable wrapper class around the class with sensitive information.
</p>
<!-- l. 64 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.4   </span> <a id="x1-90001.4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>The Driver</h4>


<!-- l. 65 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">With our two classes written, it’s time for the show. Let’s create a program that creates an instance of the sensitive
data container, set it on our wrapper, and then serialize the wrapper to file.
</p>
   

<!-- l. 67 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-9001r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-9002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>
   

<div id="listing-4" class="lstlisting" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-9003r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">package</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> swa; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-9004r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">import</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> java.io.*; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-9005r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">public</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> </span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">class</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> SerializeExample { </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-9006r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">        </span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">public</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> </span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">static</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> </span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">void</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> main(String[] args) { </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-9007r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">                 ClassA objA = </span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">new</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> ClassA("swa","123456789"); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-9008r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">                 ClassB objB = </span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">new</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> ClassB(objA); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-9009r7" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">                 </span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">try</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> { </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-9010r8" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">                         FileOutputStream fos = </span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">new</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> FileOutputStream("/home/swa/data.ser"); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-9011r9" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">                         ObjectOutputStream oos = </span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">new</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> ObjectOutputStream(fos); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-9012r10" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">                         oos.writeObject(objB); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-9013r11" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">                         oos.close(); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-9014r12" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">                         fos.close(); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-9015r13" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">                 } </span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">catch</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> (IOException i) { </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-9016r14" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">                         i.printStackTrace(); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-9017r15" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">                 } </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-9018r16" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">        } </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-9019r17" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">}</span>
<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 4:</span><span class="content">Serialization Driver</span></figcaption><!-- tex4ht:label?: x1-9001r1  -->
   
</div>


<!-- l. 88 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Time for the main event! What happens when I run this? </p>
<!-- l. 89 -->

                                                                                         
                                                                                         

<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-9020r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-9021" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>
   

<div id="listing-5" class="lstlisting" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-9022r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">java.io.NotSerializableException: swa.ClassA </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-9023r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">             at java.base/java.io.ObjectOutputStream.writeObject0(ObjectOutputStream.java:1192) </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-9024r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">             at java.base/java.io.ObjectOutputStream.defaultWriteFields(ObjectOutputStream.java:1577) </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-9025r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">             at java.base/java.io.ObjectOutputStream.writeSerialData(ObjectOutputStream.java:1534) </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-9026r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">             at java.base/java.io.ObjectOutputStream.writeOrdinaryObject(ObjectOutputStream.java:1443) </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-9027r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">             at java.base/java.io.ObjectOutputStream.writeObject0(ObjectOutputStream.java:1186) </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-9028r7" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">             at java.base/java.io.ObjectOutputStream.writeObject(ObjectOutputStream.java:352) </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-9029r8" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">             at swa/swa.SerializeExample.main(SerializeExample.java:14)</span>
<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 5:</span><span class="content">Driver Output</span></figcaption><!-- tex4ht:label?: x1-9020r1  -->
   
</div>


<!-- l. 101 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Alas, no joy. Even though <span class="ec-lmtt-10" style="font-family: monospace,monospace;">ClassA </span>contains sensitive data and does not explicitly deny serialization, I couldn’t get
at the sensitive data by serializing a wrapper. That’s a bit of a bummer–I was looking forward to being able to
trumpet this one from the rooftops.
</p>
<!-- l. 103 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.5   </span> <a id="x1-100001.5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>What Gives?</h4>


<!-- l. 104 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">So I took my disappointment and went to Google, trying to make sense of this mysterious CWE. The first thing I
found was this tidbit:
</p>
     

<blockquote class="quote">
<!-- l. 106 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;">Notice that for a class to be serialized successfully, two conditions must be met: </p>
<ul class="itemize1">    
<li class="itemize">The class must implement the java.io.Serializable interface.
</li>    
<li class="itemize">All of the fields in the class must be serializable. If a field is not serializable, it must be
marked transient.</li></ul>
<!-- l. 110 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;">[<a href="#cite.0@20210830:javaserialization" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">4</a>]</p></blockquote>


<!-- l. 113 -->
<p class="indent" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   What a refreshingly reasonable approach to have! For me to access <span class="ec-lmtt-10" style="font-family: monospace,monospace;">ClassA</span>’s sensitive data, it would have to be
made serializable.
</p>
<!-- l. 115 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.6   </span> <a id="x1-110001.6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Caveats</h4>


<!-- l. 116 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Not all serialization libraries are created equally. For example the Kryo library will work with the above example
and serialize the private data by changing the driver to the one described in Listing <a href="#x1-11001r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">6<!-- tex4ht:ref: lst:20210830:kryo  --></a>.[<a href="#cite.0@20210830:kryo" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1</a>]
</p>
   

<!-- l. 118 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-11001r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-11002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>
   

<div id="listing-6" class="lstlisting" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-11003r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">package</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> swa; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-11004r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">import</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> java.io.FileOutputStream; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-11005r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">import</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> java.io.IOException; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-11006r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">import</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> com.esotericsoftware.kryo.Kryo; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-11007r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">import</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> com.esotericsoftware.kryo.io.Output; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-11008r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">public</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> </span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">class</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> SerializeExample { </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-11009r7" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">        </span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">public</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> </span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">static</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> </span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">void</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> main(String[] args) { </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-11010r8" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">                 Kryo kryo = </span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">new</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> Kryo(); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-11011r9" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">                 kryo.register(ClassA.</span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">class</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-11012r10" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">                 kryo.register(ClassB.</span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">class</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-11013r11" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">                 ClassA objA = </span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">new</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> ClassA("swa", "123456789"); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-11014r12" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">                 ClassB objB = </span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">new</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> ClassB(objA); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-11015r13" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">                 </span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">try</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> { </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-11016r14" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">                         Output fos = </span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">new</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> Output(</span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">new</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> FileOutputStream("/home/swa/data.ser")); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-11017r15" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">                         kryo.writeObject(fos, objB); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-11018r16" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">                         fos.close(); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-11019r17" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">                 } </span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">catch</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> (IOException i) { </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-11020r18" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">                         i.printStackTrace(); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-11021r19" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">                 } </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-11022r20" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">        } </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-11023r21" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">}</span>
<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 6:</span><span class="content">Kryo Driver</span></figcaption><!-- tex4ht:label?: x1-11001r1  -->
   
</div>


<!-- l. 142 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   To prevent Kryo from serializing the private data, the fields storing the data must be marked <span class="ec-lmtt-10" style="font-family: monospace,monospace;">transient</span>.
</p>
<!-- l. 144 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   But is that really enough to protect a private class in Java? No! Kryo works by using reflection, and Java
reflection permits the developer to change the security context of even private variables. Suppose that <span class="ec-lmtt-10" style="font-family: monospace,monospace;">ssn </span>is marked
as <span class="ec-lmtt-10" style="font-family: monospace,monospace;">transient</span>. This variable may still be accessed and serialized with reflection using the driver in
Listing <a href="#x1-11024r7" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">7<!-- tex4ht:ref: lst:20210830:reflection  --></a>.
</p>
   

<!-- l. 146 -->

                                                                                         
                                                                                         

<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-11024r7" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-11025" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>
   

<div id="listing-7" class="lstlisting" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-11026r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">package</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> swa; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-11027r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">import</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> java.lang.reflect.Field; </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-11028r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">public</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> </span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">class</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> SerializeExample { </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-11029r4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">        </span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">public</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> </span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">static</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> </span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">void</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> main(String[] args) { </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-11030r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">                 ClassA objA = </span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">new</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> ClassA("swa","123456789"); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-11031r6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">                 </span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">try</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> { </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-11032r7" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">                         Field f = objA.getClass().getDeclaredField("ssn"); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-11033r8" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">                         f.setAccessible(</span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">true</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-11034r9" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">                         System.out.println(f.get(objA)); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-11035r10" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">                 } </span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">catch</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> (NoSuchFieldException e) { </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-11036r11" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">                         e.printStackTrace(); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-11037r12" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">                 } </span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">catch</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> (SecurityException e) { </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-11038r13" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">                         e.printStackTrace(); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-11039r14" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">                 } </span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">catch</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> (IllegalArgumentException e) { </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-11040r15" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">                         e.printStackTrace(); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-11041r16" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">                 } </span><span class="ec-lmtk-10x-x-70" style="font-size: 70%; font-family: monospace,monospace;">catch</span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;"> (IllegalAccessException e) { </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-11042r17" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">                         e.printStackTrace(); </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-11043r18" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">                 } </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-11044r19" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">        } </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-11045r20" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-8x-x-87" style="font-size: 69%; font-family: monospace,monospace;">}</span>
<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 7:</span><span class="content">Reflection Driver</span></figcaption><!-- tex4ht:label?: x1-11024r1  -->
   
</div>


<!-- l. 169 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.7   </span> <a id="x1-120001.7" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Conclusions</h4>


<!-- l. 170 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">So the next time I see a CWE-499, I know to check the following factors:
</p>
     

<ol class="enumerate1" style="list-style-type: decimal;">
<li id="x1-12002x1" class="enumerate">     
Does the class contain sensitive data?
</li>     
<li id="x1-12004x2" class="enumerate">
Is the class (or its parent) serializable?
</li>     
<li id="x1-12006x3" class="enumerate">
Is the field that contains the sensitive data marked transient?
</li>     
<li id="x1-12008x4" class="enumerate">
Does the project disable reflection?</li></ol>


<!-- l. 178 -->
<p class="indent" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   If the class doesn’t truly contain sensitive data, then it would be a False Positive. If it does, then the other three
factors help guide us to an appropriate conclusion. The CWE would most likely be confirmed if the class is
serializable and the field is not marked transient. But, if either of those conditions are false, then it may be a merely
informational finding. An issue could, at least theoretically, arise over the next development cycle as folks make
changes.
</p>
<!-- l. 180 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   And, that’s not all. I’ll go ahead and add one last thing to check to our list:
</p>
     

<ol class="enumerate1" style="list-style-type: decimal;">
<li id="x1-12010x5" class="enumerate">     
Is the sensitive data stored unencrypted?</li></ol>


<!-- l. 186 -->
<p class="indent" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   While this one falls under the umbrella of a different CWE (311), it’s worth checking while you’re evaluating a
instance of 499.
                                                                                         
                                                                                         
</p>
   

<h3 class="sectionHead"><a id="x1-130001.7" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>References</h3>


<!-- l. 48 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">    
</p>


<dl class="thebibliography"><dt class="thebibliography" id="X0-20210830:kryo" style="float: left; clear: left; margin-right: 1em;">
[1]  
</dt><dd class="thebibliography" id="bib-1" style="margin-left: 2.5em;">
<!-- l. 48 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20210830:kryo" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Kryo      Contributors.      Kryo. Java binary serialization and cloning.      Aug. 26,      2021.      <span class="small-caps" style="font-variant: small-caps;">url</span>:
<a href="https://github.com/EsotericSoftware/kryo" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://github.com/EsotericSoftware/kryo</span></a> (visited on 08/26/2021).
</p>    
</dd>
<dt class="thebibliography" id="X0-20210830:cwe-499" style="float: left; clear: left; margin-right: 1em;">
[2]  
</dt><dd class="thebibliography" id="bib-2" style="margin-left: 2.5em;">
<!-- l. 48 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20210830:cwe-499" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>CWE  Content  Team.  “CWE-499:  Serializable  Class  Containing  Sensitive  Data”.  In:  (2021).  <span class="small-caps" style="font-variant: small-caps;">url</span>:
<a href="https://cwe.mitre.org/data/definitions/499.html" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://cwe.mitre.org/data/definitions/499.html</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-swatips" style="float: left; clear: left; margin-right: 1em;">
[3]  
</dt><dd class="thebibliography" id="bib-3" style="margin-left: 2.5em;">
<!-- l. 48 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon Hood, ed. SwATips. <a href="https://www.SwATips.com/" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.SwATips.com/</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-20210830:javaserialization" style="float: left; clear: left; margin-right: 1em;">
[4]  
</dt><dd class="thebibliography" id="bib-4" style="margin-left: 2.5em;">
<!-- l. 48 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20210830:javaserialization" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Tutorials             Point.             Java - Serialization.             Mar. 26,             2018.             <span class="small-caps" style="font-variant: small-caps;">url</span>:
<a href="https://www.tutorialspoint.com/java/java_serialization.htm" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.tutorialspoint.com/java/java_serialization.htm</span></a> (visited on 08/26/2021).</p></dd></dl>

 

]]></description>
	</item>
