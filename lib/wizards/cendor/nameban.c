if((int)BANISH_D -> query_ban_name_time(lower_case(name)) > 0) {
if((int)BANISH_D->query_ban_name_time(lower_case(name)) < time()) {
   BANISH_D->unbanish_name(lower_case(name));
  }
}

if(BANISH_D->check_banned_name(lower_case(name))) {
  write("You have been banished because of '" +
  BANISH_D -> query_nreason(lower_case(name)) + "' by "+
  BANISH_D -> query_name_banner(lower_case(name)) + ".\n");
  destruct(this_player());
  return 0;
}