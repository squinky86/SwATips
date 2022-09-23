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
	<item>
		<title>Improper Resource Access Authorization</title>
		<link>https://www.SwATips.com/articles/20220418.html</link>
		<pubDate>Mon, 18 Apr 2022 00:00:00 -0500</pubDate>
<description><![CDATA[

<p style="margin-top: 0; margin-bottom: 0;"><a href="/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/swatips.svg" width="120" alt="SwATips" style="border-top: 0; border-left: 0; border-right: 0;"/></a>| <a href="articles/20220418.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">pdf</a> | <a rel="license" href="http://creativecommons.org/licenses/by/4.0/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/by.svg" width="60" height="21" alt="CC-BY" style="border-top: 0; border-left: 0; border-right: 0;"/></a></p>


<div class="maketitle" style="margin-top: 1em; text-align: center; margin-bottom: 2em;">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead" style="text-align: center;"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a id="x1-3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1</a>]<br/>
</h2>
<div class="author" style="text-align: center;"><span class="ec-lmr-12" style="font-size: 120%;">Kevin Keen</span></div><br/>
<div class="date" style="text-align: center;"><span class="ec-lmr-12" style="font-size: 120%;">Monday 18</span><sup class="textsuperscript"><span class="ec-lmr-9" style="font-size: 90%;">th</span></sup><span class="ec-lmr-12" style="font-size: 120%;"> April, 2022</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead" id="improper-resource-access-authorization"><span class="titlemark">1   </span> <a id="x1-10001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Improper Resource Access Authorization</h3>


<!-- l. 44 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;"><span class="ec-lmr-8" style="font-size: 80%;">Updated Friday 10</span><sup class="textsuperscript"><span class="ec-lmr-9" style="font-size: 90%;">th</span></sup><span class="ec-lmr-8" style="font-size: 80%;"> June, 2022</span>
</p>
<!-- l. 1 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Part of being a cyber security specialist is knowing the tools we use and what they are trying to communicate.
Sometimes that is not as clear as we would wish. Take for example the finding of <i>Improper Resource Access
Authorization</i> produced by Checkmarx. This is perhaps one of my least favorite findings as it tends to be very noisy,
flagging on nearly any I/O that the application performs. What is it that the scanner is trying to tell us here? Let’s
look at the corresponding CWE according to Checkmarx. The documentation from Checkmarx maps this finding to
<i>CWE-285: Improper Authorization</i>. The short description reads: “The software does not perform or
incorrectly performs an authorization check when an actor attempts to access a resource or perform an
action.”
</p>
<!-- l. 3 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   That may be a bit too general, but the gist of it is that the scanner is attempting to ask “Does the user of the
application have authorization to access the resource that is the target of this I/O operation?” In nearly
every case we do not have enough information from the code alone to answer that question. In a few
cases, the application may have the concept of users, and there might be a user check guarding the
I/O. Only in those cases do we have a chance at marking these findings a <span class="ec-lmtt-10" style="font-family: monospace,monospace;">false positive</span>. But more
often, the application has no notion of separate user roles. At that point there is no way to answer
this question from the code alone. It becomes something that must be answered by policy or external
documentation.
</p>
<!-- l. 5 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Note that a similar sounding finding from Checkmarx, <i>Exposure of Resource to Wrong Sphere</i>, is a completely
different issue dealing with whether public variables are marked final.
                                                                                         
                                                                                         
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
		<title>Ever-Changing Encryption Standards</title>
		<link>https://www.SwATips.com/articles/20220328.html</link>
		<pubDate>Mon, 28 Mar 2022 00:00:00 -0500</pubDate>
<description><![CDATA[

<p style="margin-top: 0; margin-bottom: 0;"><a href="/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/swatips.svg" width="120" alt="SwATips" style="border-top: 0; border-left: 0; border-right: 0;"/></a>| <a href="articles/20220328.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">pdf</a> | <a rel="license" href="http://creativecommons.org/licenses/by/4.0/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><img src="https://www.swatips.com/articles/images/by.svg" width="60" height="21" alt="CC-BY" style="border-top: 0; border-left: 0; border-right: 0;"/></a></p>


<div class="maketitle" style="margin-top: 1em; text-align: center; margin-bottom: 2em;">
                                                                                         
                                                                                         
                                                                                         
                                                                                         

<h2 class="titleHead" style="text-align: center;"> <strong>Software Assurance Tips</strong><br/>
A product of the Software Assurance Tips Team[<a id="x1-3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">3</a>]<br/>
</h2>
<div class="author" style="text-align: center;"><span class="ec-lmr-12" style="font-size: 120%;">Jon Hood</span></div><br/>
<div class="date" style="text-align: center;"><span class="ec-lmr-12" style="font-size: 120%;">Monday 28</span><sup class="textsuperscript"><span class="ec-lmr-9" style="font-size: 90%;">th</span></sup><span class="ec-lmr-12" style="font-size: 120%;"> March, 2022</span></div>
</div>

                                                                                         
                                                                                         
   

<h3 class="sectionHead" id="everchanging-encryption-standards"><span class="titlemark">1   </span> <a id="x1-10001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Ever-Changing Encryption Standards</h3>


<!-- l. 44 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;"><span class="ec-lmr-8" style="font-size: 80%;">Updated Monday 12</span><sup class="textsuperscript"><span class="ec-lmr-9" style="font-size: 90%;">th</span></sup><span class="ec-lmr-8" style="font-size: 80%;"> September, 2022</span>
</p>
<!-- l. 1 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   <strong>UPDATE:</strong> CNSA 2.0 information has been released, and     <a class="url" href="https://www.SwATips.com/articles/20220919.html" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.SwATips.com/articles/20220919.html</span></a>
has been updated with the latest recommendations.
</p>
<!-- l. 3 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Since 2016, National Security Systems (NSS) have been required to implement the policies put forward by the
Committee on National Security Systems (CNSS). CNSS Policy 15 details key sizes that are required to
protect national security information.[<a id="x1-1001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@20220328:cnssp15" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2</a>] To comply with CNSSP 15, system architects should use an
algorithm approved in the Commercial National Security Algorithm (CNSA) suite at a key size defined by
CNSSP 15. At the time of this writing, the following algorithms are permitted for encrypting data:
</p>
     

<ul class="itemize1">
<li class="itemize">AES with 256-bit keys
</li>
<li class="itemize">RSA with at least 3072-bit modulus
</li>
<li class="itemize">ECC with P-384</li></ul>


<!-- l. 9 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Additional requirements for key exchange and digital signatures are also provided in the policy.
</p>
<!-- l. 11 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Not only must the CNSSP 15 standards be implemented, but also the recommendations of NIST SP 800-57.[<a id="x1-1002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/><a href="#cite.0@20220328:nist80057p1r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1</a>]
Currently, the following algorithms are allowed by SP 800-57 Part 1 Rev. 5: </p>


<ul class="itemize1">     
<li class="itemize">AES with 128, 192, or 256-bit key sizes
</li>
<li class="itemize">RSA with at least 3072-bit modulus
</li>
<li class="itemize">ECC with a range of at least 256 (i.e. P-256, P-384, and P-512)</li></ul>


<!-- l. 17 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">NIST SP 800-57 further details that RSA with a 15360-bit modulus and an Elliptic Curve of at least 512 bits are
required to reach the security afforded by AES-256 (the minimum AES key size allowed by CNSSP 15). While
RSA15360 is permitted under CNSSP 15, P-512 is not.
</p>
<!-- l. 19 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   For the near future, AES-256, RSA3072, and P-384 are the permitted minimum standards for cryptography.
Engineers implementing RSA3072 or P-384 for their encryption should be ready to move to RSA15360 and P-512
respectively in anticipation of updated CNSS standards.
                                                                                         
                                                                                         
</p>
   

<h3 class="sectionHead" id="references"><a id="x1-20001" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>References</h3>


<!-- l. 49 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">    
</p>


<dl class="thebibliography"><dt class="thebibliography" id="X0-20220328:nist80057p1r5" style="float: left; clear: left; margin-right: 1em;">
[1]  
</dt><dd class="thebibliography" id="bib-1" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20220328:nist80057p1r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Elaine Barker. Recommendation for Key Management. Part 1 – General. Tech. rep. Special Publication
(SP)           800-57           Part           1           Revision           5.           Washington,           D.C.:
National Institute of Standards and Technology, 2020. <span class="small-caps" style="font-variant: small-caps;">doi</span>: <a href="https://doi.org/10.6028/NIST.SP.800-57pt1r5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">10.6028/NIST.SP.800-57pt1r5</span></a>. <span class="small-caps" style="font-variant: small-caps;">url</span>:
<a class="url" href="https://nvlpubs.nist.gov/nistpubs/SpecialPublications/NIST.SP.800-57pt1r5.pdf" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://nvlpubs.nist.gov/nistpubs/SpecialPublications/NIST.SP.800-57pt1r5.pdf</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-20220328:cnssp15" style="float: left; clear: left; margin-right: 1em;">
[2]  
</dt><dd class="thebibliography" id="bib-2" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20220328:cnssp15" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Committee                     on                     National                     Security                     Systems.
Use of Public Standards for Secure Information Sharing
. Tech. rep. CNSSP 15. Ft. Meade, MD: NSA,
2016. <span class="small-caps" style="font-variant: small-caps;">url</span>:     <a class="url" href="https://www.cnss.gov/CNSS/issuances/Policies.cfm" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.cnss.gov/CNSS/issuances/Policies.cfm</span></a>.
</p>    
</dd>
<dt class="thebibliography" id="X0-swatips" style="float: left; clear: left; margin-right: 1em;">
[3]  
</dt><dd class="thebibliography" id="bib-3" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@swatips" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon Hood, ed. SwATips.     <a class="url" href="https://www.SwATips.com/" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.SwATips.com/</span></a>.</p></dd></dl>

 

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
<p class="noindent" style="margin-top: 0; margin-bottom: 0;"><span class="rm-lmr-8" style="font-size: 80%;">Updated Tuesday 12</span><sup class="textsuperscript"><span class="rm-lmr-9" style="font-size: 90%;">th</span></sup><span class="rm-lmr-8" style="font-size: 80%;"> April, 2022</span>
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
<li class="itemize">Navy Linux Enterprise 8
</li>     
<li class="itemize">Ubuntu 20.04
</li>     
<li class="itemize">SUSE Linux Enterprise Server 15</li></ul>


<!-- l. 19 -->
<p class="indent" style="margin-top: 0; margin-bottom: 0; text-indent: 0;">   Each of these alternatives will be discussed here along with considerations DoD projects must make before they
implement one of them. The minimal installation for each of the options is selected, and an install of Tenable Nessus
10.1.1 (commercially known as ACAS) will be used to evaluate compatibility.
</p>
<!-- l. 21 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.1   </span> <a id="x1-20001.1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>RedHat Enterprise Linux 8</h4>


<!-- l. 23 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">The first competitor is the seasoned veteran of the group: RHEL. One of the benefits of CentOS 8 is that
it has been binary compatible with RHEL. Everything works out of the box, including DISA STIG
compliance, SCAP Compliance Checker, and Nessus scanning. The downside to this option is the recurring
subscription cost. Some organizations have a difficult time funding material and license purchases
(i.e. labor-cost-only contracts), It’s often difficult to use a subscription-based service contractually, even if the cost
is reasonable.
                                                                                         
                                                                                         
</p>
<!-- l. 25 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.2   </span> <a id="x1-30001.2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Oracle Linux 8</h4>


<!-- l. 27 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Oracle Linux is now the oldest kid on the block when it comes to RHEL-compatible alternatives. A
DISA STIG already exists for compliance, and a beta benchmark is available which knocks out the
majority of automated checks in the STIG. For a streamlined experience in regards to compliance and
compatibility, Oracle Linux 8 should be at the top of the list for consideration. The Nessus 10.1.1
ES8 RPM works with Oracle Linux 8, and the Oracle Linux 8 distribution is expressly supported by
Tenable.
</p>
<!-- l. 29 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.3   </span> <a id="x1-40001.3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Rocky Linux 8</h4>


<!-- l. 30 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Rocky Linux is one of the newer RHEL-binary-compatible rebuilds that attempts to recreate the RHEL
environment using the same standards that CentOS 8 used before it went EOL.
</p>
<!-- l. 32 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h5 class="subsubsectionHead"><span class="titlemark">1.3.1   </span> <a id="x1-50001.3.1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Installation Issues</h5>


<!-- l. 33 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">When applying the DISA STIG for Red Hat Enterprise Linux 8 security profile during installation, it does not
appear that the majority of the checks and configuration options (eg: partition information) are being
performed or configured. Additionally, installing with this security profile will require the installation of
openscap which will crash the installer with the minimal installation media. Rocky’s inability to maintain
compatibility with RHEL’s security baselines (when both AlmaLinux and Oracle Linux were able to do so) is
concerning.
</p>
<!-- l. 35 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h5 class="subsubsectionHead"><span class="titlemark">1.3.2   </span> <a id="x1-60001.3.2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Compliance</h5>


<!-- l. 36 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Rocky Linux does not currently have DISA risk acceptance or a standard STIG to apply. Instead, the RHEL 8
benchmark can be utilized with a note that the checks against the <span class="ec-lmtt-10" style="font-family: monospace,monospace;">CPE_NAME </span>in <span class="ec-lmtt-10" style="font-family: monospace,monospace;">/etc/os-release </span>should be
modified to look for Rocky Linux rather than RHEL. The benchmark file (such as the one installed
with SCAP Compliance Checker) can be modified to work with Rocky Linux using the command in
Listing <a href="#x1-6001r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">1<!-- tex4ht:ref: lst:20220321:rocky  --></a>.
</p>
   

<!-- l. 38 -->


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


<!-- l. 43 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   If using the RHEL benchmark for evaluating Rocky Linux, the SCAP content will flag on rules relating to using
a supported release (it checks /etc/redhat-release for this) and RedHat certificate authorities. The check content for
                                                                                         
                                                                                         
these two CAT I checks should be modified to reflect the Rocky Linux support lifecycle and certificate authorities
respectively.
</p>
<!-- l. 45 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h5 class="subsubsectionHead"><span class="titlemark">1.3.3   </span> <a id="x1-70001.3.3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Compatibility</h5>


<!-- l. 46 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">I had no problem installing the RHEL version of Nessus 10.1.1 (though it should be noted that Rocky Linux is not
listed as an officially supported distribution by Tenable). All RHEL packages installed and ran without issues, as
they did with CentOS 8. FIPS compliance was enabled and tested with the <span class="ec-lmtt-10" style="font-family: monospace,monospace;">fips-mode-setup --enable</span>
command.
</p>
<!-- l. 48 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.4   </span> <a id="x1-80001.4" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>AlmaLinux OS 8</h4>


<!-- l. 49 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">AlmaLinux OS 8, like Rocky Linux, is one of the newcomers that is attempting to court CentOS migrators.
</p>
<!-- l. 51 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h5 class="subsubsectionHead"><span class="titlemark">1.4.1   </span> <a id="x1-90001.4.1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Installation Issues</h5>


<!-- l. 52 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">The first thing that should be noted is the presence of a security profile for “DISA STIG for AlmaLinux 8.” It should
be emphasized that DISA has not released such a STIG, and the implications of there being one is disconcerting
from a DoD compliance point of view. A bug has been created with the AlmaLinux team to address this.[<a href="#cite.0@20220321:almabug" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2</a>]
Additionally, installing with this security profile selected against the minimal installation media will result in a crash
due to an inability to install openscap.
</p>
<!-- l. 54 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h5 class="subsubsectionHead"><span class="titlemark">1.4.2   </span> <a id="x1-100001.4.2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Compliance</h5>


<!-- l. 55 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">AlmaLinux does not currently have DISA risk acceptance or a standard STIG to apply. Instead, the RHEL 8
benchmark can be utilized with a note that the checks against the <span class="ec-lmtt-10" style="font-family: monospace,monospace;">CPE_NAME </span>in <span class="ec-lmtt-10" style="font-family: monospace,monospace;">/etc/os-release </span>should be
modified to look for AlmaLinux rather than RHEL. The benchmark file (such as the one installed
with SCAP Compliance Checker) can be modified to work with AlmaLinux using the command in
Listing <a href="#x1-10001r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">2<!-- tex4ht:ref: lst:20220321:alma  --></a>.
</p>
   

<!-- l. 57 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-10001r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-10002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>


<div id="listing-2" class="lstlisting" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-10003r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtti-10x-x-90" style="font-size: 90%; font-family: monospace,monospace; font-style: italic;"># sed -i -e </span><span class="ts1-lmtti10-x-x-90" style="font-size: 90%;">'</span><span class="ec-lmtti-10x-x-90" style="font-size: 90%; font-family: monospace,monospace; font-style: italic;">s|redhat:enterprise_linux\(.*\)&lt;/pattern&gt;|almalinux:almalinux\1*&lt;/pattern&gt;|g</span><span class="ts1-lmtti10-x-x-90" style="font-size: 90%;">'</span><span class="ec-lmtti-10x-x-90" style="font-size: 90%; font-family: monospace,monospace; font-style: italic;"> \</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-10004r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        /opt/scc/Resources/Content/SCAP12_Content/U_RHEL_8_*_STIG_SCAP_1-2_Benchmark.xml</span>
<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 2:</span><span class="content">Modify
RHEL
Benchmark
for
AlmaLinux</span></figcaption><!-- tex4ht:label?: x1-10001r1  -->
   
</div>


<!-- l. 62 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   If using the RHEL baseline for evaluating AlmaLinux, the SCAP content will flag for rules relating to using a
supported release (it checks /etc/redhat-release for this) and RedHat certificate authorities. The check content for
these two CAT I checks should be modified to reflect the AlmaLinux support lifecycle and certificate authorities
                                                                                         
                                                                                         
respectively.
</p>
<!-- l. 64 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h5 class="subsubsectionHead"><span class="titlemark">1.4.3   </span> <a id="x1-110001.4.3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Compatibility</h5>


<!-- l. 65 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">I had no problem installing the RHEL version of Nessus 10.1.1 (though it should be noted that Navy Linux
Enterprise is not listed as an officially supported distribution by Tenable). All RHEL packages installed and ran
without issues, as they did with CentOS 8. FIPS compliance was enabled and tested with the <span class="ec-lmtt-10" style="font-family: monospace,monospace;">fips-mode-setup
</span><span class="ec-lmtt-10" style="font-family: monospace,monospace;">--enable </span>command.
</p>
<!-- l. 67 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.5   </span> <a id="x1-120001.5" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Navy Linux Enterprise 8</h4>


<!-- l. 68 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Navy Linux Enterprise (NLE) has the same goals as Rocky Linux and AlmaLinux–being bug-for-bug compatible
with RedHat Enterprise Linux. The project is currently one year old and has seen very little activity in the Linux
community. Though not as popular as the alternatives, NLE has maintained its repositories against the latest
RHEL updates. It was the last to release version 8.5, several months behind its other competitors. This
distribution is not associated with any government’s Navy when it was ceremoniously launched by
UnixLab.
</p>
<!-- l. 70 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h5 class="subsubsectionHead"><span class="titlemark">1.5.1   </span> <a id="x1-130001.5.1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Installation Issues</h5>


<!-- l. 71 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">Unlike its competitors, NLE’s 8.5 installation media does not contain security profiles. This raises concerns for its
compatibility with being able to create similar installations to those of its competitors. While the user can enter a
URI to fetch security profiles from the internet, the software should be installable and configurable in an offline
environment.
</p>
<!-- l. 73 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h5 class="subsubsectionHead"><span class="titlemark">1.5.2   </span> <a id="x1-140001.5.2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Compliance</h5>


<!-- l. 74 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">NLE does not currently have DISA risk acceptance or a standard STIG to apply. Instead, the RHEL 8 benchmark
can be utilized with a note that the checks against the <span class="ec-lmtt-10" style="font-family: monospace,monospace;">CPE_NAME </span>in <span class="ec-lmtt-10" style="font-family: monospace,monospace;">/etc/os-release </span>should be modified to look for
NLE rather than RHEL. The benchmark file (such as the one installed with SCAP Compliance Checker) can be
modified to work with NLE using the command in Listing <a href="#x1-14001r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;">3<!-- tex4ht:ref: lst:20220321:nle  --></a>.
</p>
   

<!-- l. 76 -->


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-14001r3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>


<p style="margin-bottom: 0; margin-top: 1em;"><a id="x1-14002" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></p>


<div id="listing-3" class="lstlisting" style="font-family: monospace,monospace; white-space: nowrap; margin-top: 0.5em; margin-bottom: 0.5em;"><span class="label" style="margin-right: 0.5em;"><a id="x1-14003r1" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtti-10x-x-90" style="font-size: 90%; font-family: monospace,monospace; font-style: italic;"># sed -i -e </span><span class="ts1-lmtti10-x-x-90" style="font-size: 90%;">'</span><span class="ec-lmtti-10x-x-90" style="font-size: 90%; font-family: monospace,monospace; font-style: italic;">s|redhat:enterprise_linux\(.*\)&lt;/pattern&gt;|navylinux:navylinux\1*&lt;/pattern&gt;|g</span><span class="ts1-lmtti10-x-x-90" style="font-size: 90%;">'</span><span class="ec-lmtti-10x-x-90" style="font-size: 90%; font-family: monospace,monospace; font-style: italic;"> \</span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;"> </span><br/><span class="label" style="margin-right: 0.5em;"><a id="x1-14004r2" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/></span><span class="ec-lmtt-9" style="font-size: 90%; font-family: monospace,monospace;">        /opt/scc/Resources/Content/SCAP12_Content/U_RHEL_8_*_STIG_SCAP_1-2_Benchmark.xml</span>
<figcaption class="caption" style="text-indent: -2em; margin-left: 3em; margin-right: 1em; text-align: center;"><span class="id" style="font-weight: bold; white-space: nowrap;">Listing 3:</span><span class="content">Modify
RHEL
Benchmark
for
Navy
Linux
Enterprise</span></figcaption><!-- tex4ht:label?: x1-14001r1  -->
                                                                                         
                                                                                         
   
</div>


<!-- l. 81 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   If using the RHEL benchmark for evaluating NLE, the SCAP content will flag on rules relating to using a
supported release (it checks /etc/redhat-release for this) and RedHat certificate authorities. The check content for
these two CAT I checks should be modified to reflect the NLE support lifecycle and certificate authorities
respectively.
</p>
<!-- l. 83 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h5 class="subsubsectionHead"><span class="titlemark">1.5.3   </span> <a id="x1-150001.5.3" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Compatibility</h5>


<!-- l. 84 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">I had no problem installing the RHEL version of Nessus 10.1.1 (though it should be noted that NLE is not listed as
an officially supported distribution by Tenable). All RHEL packages installed and ran without issues, as they
did with CentOS 8. FIPS compliance was enabled and tested with the <span class="ec-lmtt-10" style="font-family: monospace,monospace;">fips-mode-setup --enable</span>
command.
</p>
<!-- l. 86 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.6   </span> <a id="x1-160001.6" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Ubuntu 20.04</h4>


<!-- l. 88 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">For workstation use, Ubuntu is one of my go-to distributions. Nevertheless, a switch from CentOS to Ubuntu
involves an architectural change that must be designed in up front rather than providing a drop-in replacement for
end-of-life CentOS software. Installation of Nessus on Ubuntu 20.04 resulted in some manual modifications before it
was able to work, and it should be noted that upgrading from Ubuntu 20.04 to the development branch of 22.04
(Jammy Jellyfish) resulted in a non-functioning Nessus installation. Nessus doesn’t support Debian 11 or Ubuntu
22.04 at this time.
</p>
<!-- l. 90 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.7   </span> <a id="x1-170001.7" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>SUSE Enterprise Linux 15</h4>


<!-- l. 92 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">The final option is SLES 15. Like RHEL, it provides enterprise-level subscription-based support. SLES 15
includes STIG content, SCAP benchmarks, and a seamless installation for products such as Nessus.
SCAP content has lagged behind its RHEL counterparts; however, the support lifecycle for SLES 15
allows DoD project planners to have the security of knowing that their underlying operating system
will be supported through July 31, 2031. It should also be noted that the STIG and SCAP content
are for the enterprise server product, while the RHEL and Oracle products include their workstation
derivatives.
</p>
<!-- l. 94 -->
<p class="noindent" style="margin-bottom: 0; margin-top: 1em;">
</p>
   

<h4 class="subsectionHead"><span class="titlemark">1.8   </span> <a id="x1-180001.8" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Concluding Remarks</h4>


<!-- l. 96 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">If you are a DoD product designer and needing to switch from CentOS 8, you have a lot of options. The most
painless (compliance-wise) is to switch to Oracle Linux or RHEL. With either of these options, you
have a robust STIG compliance framework in place to justify the decisions and a support network
that can be used if needed. Nevertheless, Oracle Linux isn’t the only free option to consider: strong
contenders from AlmaLinux, Rocky Linux, and Navy Linux Enterprise provide compatibility with very
minor compliance caveats. Instead of the General Purpose OS STIG, the RHEL STIG can be modified
to record compliance status of these operating systems; however, the AO should be informed of the
risks involving using software managed by the Rocky and Alma organizations. These organizations
are new and don’t have the prodigy of RedHat, Oracle, SUSE, or Canonical in working with DoD
projects.
                                                                                         
                                                                                         
</p>
<!-- l. 98 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Can the Authorizing Official (AO) accept the risk of allowing the AlmaLinux OS Foundation or Rocky
Enterprise Software Foundation having write/update permissions to their package repositories? Both
organizations already have the backing of Amazon, Microsoft, and Google platforms; such big names are
members of these foundations to help their governance and future direction. The Navy Foundation is a
newcomer to the community without the backing of any big names. The current lack of DoD-level risk
acceptance should be acknowledged by the AO, but such an acceptance may not be seen as a high
risk.
</p>
<!-- l. 100 -->
<p class="indent" style="margin-bottom: 0; margin-top: 1em; text-indent: 0;">   Finally, AlmaLinux supports the ELevate project which allows users to move to AlmaLinux, Rocky Linux, and
Oracle Linux from CentOS 7 (<a href="https://wiki.almalinux.org/elevate/" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://wiki.almalinux.org/elevate/</span></a>), and there are a few other tools available
for migrating from CentOS 8 to one of the supported RHEL variants.
                                                                                         
                                                                                         
</p>
   

<h3 class="sectionHead"><a id="x1-190001.8" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>References</h3>


<!-- l. 49 -->
<p class="noindent" style="margin-top: 0; margin-bottom: 0;">    
</p>


<dl class="thebibliography"><dt id="X0-20220321:centos-eol" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[1]  
</dt><dd id="bib-1" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20220321:centos-eol" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>CentOS.            CentOS Linux EOL.            CentOS.            Dec. 31,            2021.            <span class="small-caps" style="font-variant: small-caps;">url</span>:
<a href="https://www.centos.org/centos-linux-eol/" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://www.centos.org/centos-linux-eol/</span></a>.
</p>    
</dd>
<dt id="X0-20220321:almabug" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[2]  
</dt><dd id="bib-2" class="thebibliography" style="margin-left: 2.5em;">
<!-- l. 49 --><p class="noindent" style="margin-top: 0; margin-bottom: 0;"><a id="cite.0@20220321:almabug" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"/>Jon        Hood.        AlmaLinux Bug Tracker.        AlmaLinux.        Mar. 21,        2022.        <span class="small-caps" style="font-variant: small-caps;">url</span>:
<a href="https://bugs.almalinux.org/view.php?id=202" class="url" style="overflow-wrap: break-word; word-wrap: break-word; word-break: break-word; hyphens: auto;"><span class="ec-lmtt-10" style="font-family: monospace,monospace;">https://bugs.almalinux.org/view.php?id=202</span></a>.
</p>    
</dd>
<dt id="X0-swatips" class="thebibliography" style="float: left; clear: left; margin-right: 1em;">
[3]  
</dt><dd id="bib-3" class="thebibliography" style="margin-left: 2.5em;">
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
