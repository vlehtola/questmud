object player;

void start(object ob) {
  player = ob;
   if(player->query_haste()) return;
  shadow(player,1);
  call_out("desti",1800);
}

status restore_time_points() {
  if(player->restore_time_points()) return 1;
  player->restore_time_points();
}

void desti() {
  tell_object(player,"The haste fades away, as it leaves you alone on your tired form.\n");
  player->set_ep(0);
  destruct(this_object());
}

status query_haste() { return 1; }
