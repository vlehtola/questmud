inherit "room/room";

reset(arg) {
set_not_out(1);

add_exit("out", "/wizards/irmeli/nyx/ruins3");
add_exit("east", "/wizards/irmeli/nyx/cavern2.c");

short_desc = "Inside the volcano, in a ice-cavern";
long_desc = "Carved inside the mountain, inside the volcano, a gloomy ice-cavern giving\n"+
            "shelter from the volcanic eruptions. The cavern is cold, actually the air is\n"
            "is freezing, so freezing that, it's hard to even breath without freezing\n"+
            "your lungs. The walls and the ceiling are covered beneath ice, as well as\n"+
            "the ground. The northern wall is covered with the thickest ice-curtain.\n";

  if(!present("statue")) {
    move_object(clone_object("/wizards/irmeli/nyx/object/statue.c"), this_object());
  }
}
