inherit "room/room";
int a, i = 0;

reset(arg) {
 if(arg) return;
 set_light(3);
 short_desc = "In the Cloud Tower";
 long_desc = "Only walls and cracks.\n";
 add_exit("north", "/wizards/rimber/cloudc/room43.c");
 set_not_out(1);
}

search_finished(str) {
 object key;
 if(str == "cracks" || str == "crack") {
 key = clone_object("/wizards/rimber/cloudc/obj/key1.c");
  write("You found a key.\n");
  say(this_player()->query_name()+" found a key.\n");
  move_object(key, this_player());
  i = 1;
  return 1;
 }
return 0;
}

int seina() {
 tell_room(environment(this_player()), "Suddenly the tower starts shaking.\n");
 call_out("aika", 6);
}

int aika() {
 tell_room(environment(this_player()), "The tower stops shaking.\n");
 tell_room(environment(this_player()), "The archangel Micheal thunders: 'How dare you disturp me?'\n");
 add_exit("stairs", "/wizards/rimber/cloudc/room45.c");
}
