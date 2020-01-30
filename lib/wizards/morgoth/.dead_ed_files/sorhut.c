inherit "room/room";
object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/morgoth/forest/npc/sorcerer");
    move_object(monster, this_object());
  }
  if(arg) return;

  add_exit("out","/wizards/morgoth/forest/room/forest21");
short_desc = "Inside of sorcerers hut.";
long_desc = "You are standing inside of a small hut. Walls of this hut\n"+
              "are made of some ancient looking oak. There are some\n"+
              "bookshelves containing magical scrolls and spellbooks.\n"+
              "You can easily sense evil magic inside this hut.\n";

items = allocate(4);
items[0] = "bookshelf";
items[1] = "This bookshelf contains magical scrolls and spellbooks";

}.
x
laod sorhut
load sorhut.c
update sorhut

goto sorhut
l
home
l
dest morgoth
quit
l
l
sc
score
exit
quit
exit
quit
goto
trans
trans quest-1
dest

l
score
home

home
l
inn
say ei mitaan
tell guest-1 z
