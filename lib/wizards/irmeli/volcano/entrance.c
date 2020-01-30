inherit "room/room";

reset(arg) {
  if(!present("sign")) { 
    move_object(clone_object("/wizards/irmeli/volcano/objects/sign.c"),
    this_object());
 }
 if (arg) { return; }

     add_exit("tunnel", "/wizards/irmeli/volcano/tunnel1.c");
     add_exit("south", "out: 207 128");

short_desc = "Entrance to the Volcano";
long_desc = "A dormant volcano rises up to the sky, running through the clouds. The top\n"
            "of the volcano is among the clouds, making impossible to estimate its height.\n"
            "The volcano is the highest mountain nearby. A small tunnel, drived in the\n"+
            "hillside, is covered with ash, tuff and lava rock. The tunnel is leading\n"
            "deep inside the volcano. Among other gases, sulphur and nitrogen gases\n"
            "are hovering from the tunnel, from the depths of the earth.\n";
}
