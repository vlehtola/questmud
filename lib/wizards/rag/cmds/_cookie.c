status unidle(object ob) {
  if(query_idle(ob) < 300) return 1;
  return 0;
}

status not_wiz(object ob) {
  return !ob->query_wiz();
}

int cmd_cookie(string str) {
  object *us, winner;

  //Default: random user
  if ( !str ) {
    us = filter_array(users(),"unidle");
    us = filter_array(us,"not_wiz");
    if ( !sizeof(us) ) {
      write("No winner, damn those idlers!\n");
      return 1;
    }
    winner = us[ random( sizeof(us) ) ];
  } else {
    //Specific cookie
    winner = find_player( lower_case(str) );
  }

  if ( !winner ) {
    write("No winner, damn those idlers!\n");
    return 1;
  }


  move_object(clone_object("/wizards/rag/misc/cookie"),winner);
  shout("Random cookie!\n");
  tell_object(winner,"You just received a random cookie from "+this_player()->query_name()+"!\n");
  write("Cookie given to "+winner->query_name()+".\n");
  return 1;
}
