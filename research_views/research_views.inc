<?php

/*
 * page callback to provide view of user's research or a 'my-research' editing page
 */
function research_views_view_research ($research_user = NULL) {
  global $user;
  if (is_object($research_user)) {
    if ($research_user->uid == $user->uid) {
      // if user is looking at their own research
      $page = views_embed_view('my_research', 'default', $user->uid);
    } else {
      // if user looking at another researcher's research listing
      $page = views_embed_view('user_research', 'default', $research_user->uid);
    }
  }
  else {
    $page ='<p>The specified researcher could not be found</p>';
  }
  return $page;
}

/*
 * page callback to provide 'my-research' editing page
 */
function research_views_view_myresearch () {
  global $user;
  $page = '<h1>'.drupal_ucfirst($user->name).'\'s research</h1>';
  // set_context()?
  $page .= views_embed_view('my_research', 'default', $user->uid);
  
  return $page;

}

