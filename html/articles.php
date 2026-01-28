<!doctype html>
<html lang="en">
<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Software Assurance Tips - Article Archive</title>
	<meta name="description" content="Complete archive of Software Assurance Tips articles" />
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
		}

		.back-link {
			display: inline-flex;
			align-items: center;
			gap: 8px;
			color: white;
			text-decoration: none;
			font-weight: 600;
			margin-bottom: 20px;
			transition: opacity 0.3s ease;
		}

		.back-link:hover {
			opacity: 0.8;
		}

		header h1 {
			font-size: 2.5em;
			margin-bottom: 10px;
			font-weight: 700;
			letter-spacing: -0.5px;
		}

		header p {
			font-size: 1em;
			opacity: 0.95;
		}

		main {
			padding: 40px;
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
				padding: 20px;
			}
		}

		.year-group {
            margin-bottom: 20px;
            border: 1px solid #e0e0e0;
            border-radius: 8px;
            overflow: hidden;
            background: #ffffff;
        }

        .year-group summary {
            background: #f0f2f9;
            padding: 15px 20px;
            font-size: 1.5em;
            font-weight: 700;
            cursor: pointer;
            outline: none;
            color: #333;
            border-bottom: 1px solid #e0e0e0;
            transition: background 0.3s ease;
        }

        .year-group summary:hover {
            background: #e0e2e9;
        }

        .year-group summary::-webkit-details-marker {
            display: none;
        }

        .year-group[open] summary {
            background: #e0e2e9;
            border-bottom-color: #d0d2d9;
        }

        .year-group ul {
            padding: 20px;
        }

        .year-group ul li {
            background: #ffffff;
            border-left-color: #5a67d8;
        }

        .year-group ul li:hover {
            background: #f8f9fa;
        }
	</style>
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
