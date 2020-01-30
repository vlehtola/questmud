inherit "room/room";

reset(arg) {
call_other("/wizards/yodin/areas/village/field/virtual_map", "XX", 0);
  if(arg) return;
  add_exit("north", "/wizards/yodin/areas/village/field/virtual_map: 26 21");
  add_exit("southwest", "/wizards/yodin/areas/village/vh11.c");

  short_desc = "park entrance";
  long_desc = 	"You have arrived to the gates of town park. You see trees all around\n" +
				"you. Some dog barking can be heard in distance. Some people are\n" +
				"walking in the park carrying picnic baskets with them. Maybe you\n" +
				"should go to spend some time in park and relax a bit.\n";

}

