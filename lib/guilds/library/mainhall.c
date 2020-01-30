inherit "room/room";
object monster;

reset(arg) {
  if(!present("librarian")) { 
    move_object(clone_object("/guilds/library/librarian.c"),
    this_object());
 }

 if (arg) { return; }

set_not_out(1);
set_light(3);

add_exit("north","/guilds/library/hallway.c");

short_desc = "The mainhall of library of Duranghom";
long_desc =
"This is the mainhall of the library, library of Duranghom. Bookshelf after\n"+
"bookshelf, which are holding thousands of old books and scrolls, are covering\n"+
"the whole library mainhall. The books and scrolls store all the knowledge in\n"+
"the world. Knowledge from side to side, from food recipes to history books.\n"+              
"The bookshelves are arranged so, that there is space for tables and chairs\n"+
"between them. Tables are used for one purpose, for reading. It's peaceful\n"+
"and quiet in here. The light comes from the torches, which are burning on\n"+
"the granite walls, everywhere around the library. A broad hallway leads\n"+
"out from the library, north from here.\n"+
"A plaque hangs from the southern eastern wall.\n";

   items = allocate(6);
   items[0] = "torches";
   items[1] = "Burning torches are placed on the walls, around the library mainhall";
   items[2] = "shelves";
   items[3] = "The bookshelves are full of old scrolls and books";
   items[4] = "plaque";
   items[5] = 
"Welcome to the Duranghom library!\n"+
"This building is meant to be of help for all magic users.\n"+
"Say to the librarian which section you want in to. (ex. essence)\n"+
"When searching for books you need to have some knowledge of the section's skills,\n"+
"meaning that for example you have to be a mage to access the essence books.\n"+
"Search result is proportional to your knowledge (skills)";

   property = allocate(4);
   property[0] = "no_kill";
   property[1] = "no_skill";
   property[2] = "no_spell";
   property[3] = "no_summon";
}
