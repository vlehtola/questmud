inherit "room/outroom";

start() {
  mapfile = "/wizards/yodin/areas/plains/virtual_map";
  short_desc = "Old Forest";
  long_desc = 	"Trees are growing here and there, somewhat slowing\n" +
				"your movement. You can see the sky above you\n" +
				"and hear the sounds of various animals. There is a\n" +
				"multitude of plants and other flora growing here.\n";

}

reset() {
  ::reset();

if(!present("moose") && !random(2)) {
move_object(clone_object("/wizards/yodin/areas/plains/monsters/moose"), this_object());
  }
}
