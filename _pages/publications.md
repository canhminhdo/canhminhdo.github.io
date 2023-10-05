---
layout: page
permalink: /publications/
title: Publications
description: 
nav: true
nav_order: 4
---
<!-- _pages/publications.md -->
<div class="publications">
<span class="badge font-weight-bold danger-color-dark align-middle" style="width: 110px;">
    Conference <span class="badge badge-danger">{% bibliography_count -f {{ site.scholar.bibliography }} --query @inproceedings %}</span>
</span>
<span class="badge font-weight-bold primary-color-dark align-middle" style="width: 110px;">
    Journal <span class="badge badge-primary">{% bibliography_count -f {{ site.scholar.bibliography }} --query @article %}</span>
</span>
<!-- <span class="badge font-weight-bold success-color-dark align-middle" style="width: 110px;">
    Book Chapter <span class="badge badge-success">{% bibliography_count -f {{ site.scholar.bibliography }} --query @book %}</span>
</span> -->
{% bibliography -f {{ site.scholar.bibliography }} %}
</div>

<div class="publications">
<h2>Papers Under Review</h2>
<span class="badge font-weight-bold danger-color-dark align-middle" style="width: 110px;">
    Conference <span class="badge badge-danger">{% bibliography_count -f {{ site.scholar.bibliography_review }} --query @inproceedings %}</span>
</span>
<span class="badge font-weight-bold primary-color-dark align-middle" style="width: 110px;">
    Journal <span class="badge badge-primary">{% bibliography_count -f {{ site.scholar.bibliography_review }} --query @article %}</span>
</span>
{% bibliography -f {{ site.scholar.bibliography_review }} %}
</div>

<div class="publications">
<h2>Papers Under Preparing</h2>
<span class="badge font-weight-bold danger-color-dark align-middle" style="width: 110px;">
    Conference <span class="badge badge-danger">{% bibliography_count -f {{ site.scholar.bibliography_prepare }} --query @inproceedings %}</span>
</span>
<span class="badge font-weight-bold primary-color-dark align-middle" style="width: 110px;">
    Journal <span class="badge badge-primary">{% bibliography_count -f {{ site.scholar.bibliography_prepare }} --query @article %}</span>
</span>
{% bibliography -f {{ site.scholar.bibliography_prepare }} %}
</div>

