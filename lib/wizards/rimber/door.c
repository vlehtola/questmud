inherit "room/room";
inherit "room/door";
reset(arg) {
     short_desc = "At the yard";
    long_desc = "ssg  You stand on a large courtyard. The ground is sandy.\n"+
"T*g  Fortress has two strong walls. Behind the fortress\n"+
"ssg  is the insurmountable mountains.\n"+
"     West from you is the entrance to the tower which is\n"+
"     called the Tower of Blue Light.\n"+
"     East from you is the towers garden.\n";
   set_light(5);

add_exit("northwest" , "wizards/moonstar/areas/wasteland/fortress/yard8.c");
add_exit("north" , "wizards/moonstar/areas/wasteland/fortress/yard9.c");
add_exit("northeast" , "wizards/moonstar/areas/wasteland/fortress/garden3.c");
add_exit("east" , "wizards/moonstar/areas/wasteland/fortress/garden5.c");
add_exit("southwest" , "wizards/moonstar/areas/wasteland/fortress/yard17.c");
add_exit("south" , "wizards/moonstar/areas/wasteland/fortress/yard18.c");
add_exit("southeast" , "wizards/moonstar/areas/wasteland/fortress/garden6.c");
        
door_reset();
        set_door_label("Huge iron door",1);
        set_door_dir("west", "/wizards/moonstar/areas/wasteland/torni/room1",1);
        set_door_link("/wizards/moonstar/areas/wasteland/torni/room1",1);
        set_door_code("999", 1);
        set_locked(1, 1);

}

init() {
  ::init();
  door_init();
}
