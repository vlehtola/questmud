inherit "room/room";

reset(arg) {
call_other("/wizards/yodin/areas/plains/virtual_map", "XX", 0);
  if(arg) return;
  add_exit("north", "/wizards/yodin/areas/plains/virtual_map: 26 21");
  add_exit("outtiin", "outworldi niiq");

  short_desc = "Large forest";
  long_desc = 	"You have arrived in front of the huge sized forest.\n" +
				"Large trees rises to skies and allaround you there are\n" +
				"small bushes. You can hear some animal sounds from the\n" +
				"forest.\n";

}

