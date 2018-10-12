<?xml version="1.0" encoding="utf-8"?>
<rss version="2.0" xmlns:sparkle="http://www.andymatuschak.org/xml-namespaces/sparkle" xmlns:dc="http://purl.org/dc/elements/1.1/">
	<channel>
		<title>ClashX ChangeLog</title>
		<link>https://github.com/yichengchen/clashX</link>
		<description>Most recent changes with links to updates.</description>
		<language>cn</language>
		{% for release in site.github.releases %}
		{%- unless release.draft -%}
		{%- unless release.prerelease and page.release_only -%}
		<item>
			<title>{{ release.name }}</title>
			<description><![CDATA[{{ release.body | markdownify }}]]></description>
			<pubDate>{{ release.published_at | date_to_rfc822 }}</pubDate>
			<enclosure
				url="{{ asset.browser_download_url }}"
				sparkle:version="{{ release.tag_name }}"
				type="application/octet-stream"
			/>
		</item>
		{%- endunless -%}
		{%- endunless -%}
		{% endfor %}
	</channel>
</rss>