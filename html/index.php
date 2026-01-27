<!doctype html>
<html lang="en">
<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Software Assurance Tips</title>
	<meta name="description" content="Software Assurance Tips - A collection of software assurance best practices and insights" />
	<link rel="feed" type="application/rss+xml" title="SwATips" href="rss.php">
	<style>
		* {
			margin: 0;
			padding: 0;
			box-sizing: border-box;
		}

		body {
			font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto, "Helvetica Neue", Arial, sans-serif;
			line-height: 1.6;
			color: #333;
			background: linear-gradient(135deg, #f5f7fa 0%, #c3cfe2 100%);
			min-height: 100vh;
			padding: 20px;
		}

		.container {
			max-width: 1000px;
			margin: 0 auto;
			background: white;
			border-radius: 10px;
			box-shadow: 0 10px 40px rgba(0, 0, 0, 0.1);
			overflow: hidden;
		}

		header {
			background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
			color: white;
			padding: 60px 40px;
			text-align: center;
		}

		header h1 {
			font-size: 2.5em;
			margin-bottom: 15px;
			font-weight: 700;
			letter-spacing: -0.5px;
		}

		header p {
			font-size: 1.1em;
			opacity: 0.95;
		}

		main {
			padding: 60px 40px;
		}

		.intro-section {
			margin-bottom: 50px;
		}

		.intro-section p {
			font-size: 1.05em;
			line-height: 1.8;
			color: #555;
			margin-bottom: 15px;
		}

		.articles-section {
			margin-bottom: 50px;
		}

		.section-header {
			display: flex;
			align-items: center;
			gap: 15px;
			margin-bottom: 30px;
			border-bottom: 3px solid #667eea;
			padding-bottom: 15px;
		}

		.section-header h2 {
			font-size: 1.8em;
			color: #333;
			margin: 0;
		}

		.rss-icon {
			height: 28px;
			width: 28px;
			display: inline-block;
		}

		ul {
			list-style: none;
		}

		li {
			margin-bottom: 12px;
			padding: 15px;
			background: #f8f9fa;
			border-left: 4px solid #667eea;
			border-radius: 4px;
			transition: all 0.3s ease;
		}

		li:hover {
			background: #f0f2f9;
			transform: translateX(5px);
		}

		li a {
			color: #667eea;
			text-decoration: none;
			font-weight: 600;
			transition: color 0.3s ease;
		}

		li a:hover {
			color: #764ba2;
			text-decoration: underline;
		}

		.source-section {
			background: #f8f9fa;
			padding: 30px;
			border-radius: 8px;
			margin-top: 50px;
		}

		.source-section h2 {
			font-size: 1.4em;
			margin-bottom: 15px;
			color: #333;
		}

		.source-section p {
			line-height: 1.8;
			color: #555;
		}

		.source-section a {
			color: #667eea;
			text-decoration: none;
			font-weight: 600;
		}

		.source-section a:hover {
			color: #764ba2;
			text-decoration: underline;
		}

		footer {
			background: #f8f9fa;
			padding: 30px 40px;
			text-align: center;
			color: #666;
			font-size: 0.9em;
			border-top: 1px solid #e0e0e0;
		}

		@media (max-width: 768px) {
			header {
				padding: 40px 20px;
			}

			header h1 {
				font-size: 1.8em;
			}

			main {
				padding: 30px 20px;
			}

			.section-header h2 {
				font-size: 1.4em;
			}
		}
	</style>
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
