int temp;
object plr;

start() {
	temp = time();
	plr = this_player();
  shadow(plr,1);
  write("You feel divine forces hiding your activities.\n");
}

idle() {
  int i;
  if ( this_player()->query_wiz() ) {
    return plr->idle();
  }
  i = time() - temp;
  return i;
}

end_shadow() {
  write("You feel strange.\n");
  destruct(this_object());
}