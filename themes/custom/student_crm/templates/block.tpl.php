<?php
/*
* Override the core block theme to remove unnecessary fluff
*/
?>
<div id="<?php print $block_html_id; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <?php print render($title_prefix); ?>
<?php if ($block->subject): ?>
  <h2 class="block-title"><?php print $block->subject ?></h2>
<?php endif;?>
  <?php print render($title_suffix); ?>
    <?php print $content ?>
</div>
