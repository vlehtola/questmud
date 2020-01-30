inherit "room/room";

reset(status arg) {
  if(arg) return;
add_exit("post","/world/city/post");
add_exit("test","/wizards/kuaffel/testroom");
  add_exit("inn","/world/city/inn");
  add_exit("cs","/world/city/cs");
  short_desc = "Kuaffel's Room";
long_desc = "You enter a room that has nothing but a big ghostly book floating in mid-air.\n"+
     "The book is see-through and offers but a faint light to the dark walls.\n"+
     "Little will you know that this book alters the very core of your being...\n\n";
  property = allocate(1);
  property[0] = "no_summon";

  set_light(3);
}
