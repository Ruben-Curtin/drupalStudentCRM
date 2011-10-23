<div id="header">
	<div class="container">
		<div class="narrow sidebar">
			<?php if ($site_name): ?>
				<h1>
					<?php if ($logo): ?>
					<a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home">
						<img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
					</a>
					<?php endif; ?>
					<a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home">
						<?php print $site_name; ?>
					</a>
				</h1>
			<?php endif; ?>
		</div>
		<div class="content-container">
			<?php if($page['header_middle']): ?>
				<div class="fluid">
					<?php print render($page['header_middle']); ?>
				</div>
			<?php endif; ?>
			<?php if($page['header_right']): ?>
				<div class="narrow sidebar right">
					<?php print render($page['header_right']); ?>
				</div>
			<?php endif; ?>
		</div>
	</div>
	<div class="clear"></div>
</div>
<?php if ($messages): ?>
    <div id="messages">
	      <?php print $messages; ?>
    </div>
<?php endif; ?>
<div id="page" <?php if($page['sidebar_right']) { print 'class="has-right-sidebar"'; } ?>>
	<div class="container">
		<?php if($page['sidebar_left']): ?>
			<div id="sidebar-left" class="sidebar left narrow">
				<?php print render($page['sidebar_left']); ?>
			</div>
		<?php endif; ?>
		
		<div id="content-wrapper" class="content-container">
			
			<?php if($page['sidebar_right']): ?>
				<div id="sidebar-right" class="sidebar right narrow">
					<?php print render($page['sidebar_right']); ?>
				</div>
			<?php endif; ?>
			<div class="fluid" id="content">
			<?php if(!$is_front && $title): ?>
					<h2 id="page-title"><?php print $title; ?></h2>
				<?php endif; ?>
				<?php if ($tabs = render($tabs)): ?>
		       		<div class="tabs"><?php print $tabs; ?></div>
		      	<?php endif; ?>
				<?php if($page['help']): ?>
					<div id="help">
						<?php print render($page['help']); ?>
					</div>
				<?php endif; ?>
				<?php if($page['content_top_wide']): ?>
					<div id="content-top" class="content-area">
						<?php print render($page['content_top_wide']); ?>
					</div>
				<?php endif; ?>
				<?php if($page['content_top_left'] || $page['content_top_right']): ?>
					<div id="content-top-regions" class="content-area">
						<div class="column">
							<?php print render($page['content_top_left']); ?>
						</div>
						<div class="column">
							<?php print render($page['content_top_right']); ?>
						</div>
						<div class="clear"></div>
					</div>
				<?php endif; ?>
				
				<?php print render($page['content']); ?>
				
				<?php if($page['content_bottom']): ?>
					<div id="content-bottom" class="content-area">
						<?php print render($page['content_bottom']); ?>
					</div>
				<?php endif; ?>
			</div>
			
			<div class="clear"></div>
		</div>
		<div class="clear"></div>
	</div>
</div>