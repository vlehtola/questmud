object player;
int time;

void start(object ob,int bonus) {
  player = ob;
  time = bonus+random(30);
  tell_object(player, "You start to move faster!\n");
  shadow(player,1);
  call_out("end_haste",time);
}

status restore_time_points() {
  if(player->restore_time_points()) return 1;
  if(random(100) > random(100)) {
  player->restore_time_points();
  tell_object(player,"You move with haste!\n");
}
}

/* jos haste dispellataan (remove prots) niin ept� ei kulu //Celtron */
void end_haste(status no_ep_loss) {
  if(!no_ep_loss) {
    tell_object(player,"The haste fades away, as it leaves you alone on your tired form.\n");
    player->set_ep(1);
  } else {
    tell_object(player, "You slow down.\n");
  }
  tell_room(environment(player), player->query_name()+" seems to move slower.\n", ({ player, }) );
  destruct(this_object());
}

status query_haste() { return 1; }
