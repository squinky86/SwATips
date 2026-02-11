<!doctype html>
<html lang="en">
<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Software Assurance Tips - Article Archive</title>
	<meta name="description" content="Complete archive of Software Assurance Tips articles" />
	<link rel="stylesheet" href="styles.css">
</head>
<body>
	<div class="container">
		<header>
			<a href="index.php" class="back-link">← Return to Home</a>
			<h1>Article Archive</h1>
			<p>Complete collection of all published articles</p>
		</header>
		<main>
			<?PHP
				$articlesContent = file_get_contents('articles-full.inc');
				$articles = explode("</li>", $articlesContent);
				array_pop($articles); // Remove the last empty element

				$articlesByYear = [];
				foreach ($articles as $article) {
					$article = trim($article);
					if (preg_match('/^<li>(\d{8}) - <a href="(articles\/\d{8}\.html)">([^<]+)<\/a>$/', $article, $matches)) {
						$datestamp = $matches[1];
						$year = substr($datestamp, 0, 4);
						$monthDay = date('M d', strtotime($datestamp));
						$link = $matches[2];
						$title = $matches[3];
						$articlesByYear[$year][] = "<li>$monthDay - <a href=\"$link\">$title</a></li>";
					}
				}

				krsort($articlesByYear); // Sort years in descending order

				$currentYear = date('Y');

				foreach ($articlesByYear as $year => $articles) {
					$expanded = ($year == $currentYear) ? 'open' : '';
					echo "<details class=\"year-group\" $expanded>";
					echo "<summary>$year</summary>";
					echo "<ul>";
					foreach ($articles as $article) {
						echo $article;
					}
					echo "</ul>";
					echo "</details>";
				}
			?>
		</main>
		<footer>
			<p>&copy; 2021-2026 Software Assurance Tips. Some rights reserved. Please see the terms of the Creative Commons Attribution license.</p>
		</footer>
	</div>
</body>
</html>
