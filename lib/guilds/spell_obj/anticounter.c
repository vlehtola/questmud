object player;
int time,extra;

start(object ob,int bonus) {
  player = ob;
  time = bonus;
  extra = bonus/25;
  call_out("end_anticounter",time);
  tell_object(player, "You are surrounded by anti countering field.\n");
  shadow(player, 1);
}

end_anticounter() {
  tell_object(player,"The anti counter field around you fades away.\n");
  destruct(this_object());
}

query_anticounter() { return 1; }

query_anticounter_bonus() { return extra; }
