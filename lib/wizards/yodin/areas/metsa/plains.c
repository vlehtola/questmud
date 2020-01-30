inherit "room/outroom";

start() {
mapfile = "/wizards/yodin/areas/metsa/virtual_map";
  short_desc = "Plains";
  long_desc = 	"Long grass grows all over the place as far as you\n" +
				"can see. The ground is covered with various bushes\n" +
				"and plants. Occassionally you notice some signs of\n" +
				"wildlife and hear the animals' desolate cries.\n";
}
reset() {
  ::reset();
if(!present("reindeer") && !random(2)) {
move_object(clone_object("/wizards/yodin/areas/metsa/monsters/reindeer"), this_object());
  }
 }

