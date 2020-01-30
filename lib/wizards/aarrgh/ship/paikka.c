inherit "room/room";
reset(arg)  {
add_exit("pissapoika", "/wizards/aarrgh/workroom.c");
short_desc = "huarapaikka!";
long_desc = "This place is clearly a prison. The are chains in the wall\n"+
  "to attach to poor prisoners to wait to be sacrificed to Morfeus.\n";
set_light(1);
set_not_out(1);
if(!present("sailor"))  {
move_object(clone_object("/wizards/aarrgh/ship/sailor"), this_object());
}
if(!present("sailor 2"))  {
move_object(clone_object("/wizards/aarrgh/ship/sailor"), this_object());
}
}
