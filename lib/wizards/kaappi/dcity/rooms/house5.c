inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("east", "katu12.c");

  short_desc = "A noble house";
  long_desc = "A nicely decorated house with large amount of valuable looking\n"+
              "furniture. There are few paintings here and there on the walls.\n"+
              "An elegant looking maple table is standing in the vicinity of\n"+
              "the southern wall, where is also an astonishing looking fireplace.\n"+
              "A dark brown bear hide is laid on the floor and it feels comfortable\n"+
              "under your feet.\n";  
  set_light(3);
}
