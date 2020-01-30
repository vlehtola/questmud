inherit "/room/room";

reset(arg) {
  if(arg) return;
  short_desc = "Inside the wooden hut";
  long_desc =
"A strong and fierce smell of sweat and beer emits from the next room.\n"+
"There seems to be somekind of a drinking party. The walls are made of\n"+
"huge tree trunks and there is no floor at all. The ceiling has blackened\n"+
"from the smoke during years.\n";
  add_exit("out", "/wizards/siki/island/bhouse1");
  add_exit("south", "/wizards/celtron/ogremage/2");
}
