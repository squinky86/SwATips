<?PHP header('Content-type: application/rss+xml'); ?>
<?xml version="1.0"?>
<!-- Generated by SwATips on <?PHP echo (new DateTime('NOW'))->format(DateTime::ISO8601); ?> -->
<rss version="2.0">
<channel>
	<title>SwATips</title>
	<link>https://www.SwATips.com</link>
	<description>Software Assurance Tips and Tricks</description>
	<language>en-us</language>
	<ttl>1440</ttl>
<?PHP require('rss.inc'); ?>
</channel>
</rss>
