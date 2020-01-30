cmd_goo(str) {
  object ob;
  if ( !str ) return 1;

  ob = find_living(str);

  if ( environment(ob) ) {
    move_object(this_player(),environment(ob));
  }
  return 1;
}
