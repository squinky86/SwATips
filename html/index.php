<!doctype html>
<html lang="en">
<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Software Assurance Tips</title>
	<meta name="description" content="Software Assurance Tips - A collection of software assurance best practices and insights" />
	<link rel="feed" type="application/rss+xml" title="SwATips" href="rss.php">
	<link rel="stylesheet" href="styles.css">
	<style>header { text-align: center; }</style>
</head>
<body>
	<div class="container">
		<header>
			<h1>Software Assurance Tips</h1>
			<p>Expert insights and best practices for software assurance</p>
		</header>
		<main>
			<section class="intro-section">
				<p>The Software Assurance Tips contain fully unclassified, publicly released musings of an Army Software Assurance team. While issues are shared with the team, we sometimes encounter tips and tricks that are better to share with the community. The contents of these tips are the opinions of their respective authors and should not be interpreted as an official policy of any organization.</p>
			</section>

			<section class="articles-section">
				<div class="section-header">
					<h2>Latest Articles</h2>
					<a href="rss.php" title="Subscribe to RSS Feed"><img class="rss-icon" src="images/rss.svg" alt="RSS Feed" /></a>
				</div>
				<p style="margin-bottom: 20px; color: #666;">Only the most recent 10 articles are displayed here and in the RSS feed. For a complete archive, visit the <a href="articles.php" style="color: #667eea; text-decoration: none; font-weight: 600;">Articles Archive</a>.</p>
				<ul>
					<?PHP require('articles.inc'); ?>
				</ul>
			</section>

			<section class="source-section">
				<h2>Website Source Code</h2>
				<p>The source code for this website is released to the public domain under the <strong>CC-0 license</strong>. The article content is released under the <strong>CC-BY license</strong>. Source and article contents can be obtained from the <a href="https://www.github.com/squinky86/SwATips/">GitHub repository</a>.</p>
			</section>
		</main>
		<footer>
			<p>&copy; 2021-2026 Software Assurance Tips. Some rights reserved. Please see the terms of the Creative Commons Attribution license.</p>
		</footer>
	</div>
</body>
</html>
