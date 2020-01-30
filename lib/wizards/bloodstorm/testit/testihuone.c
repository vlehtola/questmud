inherit "room/room";

reset(status arg) 
{
  if(arg) return;

  add_exit("bladis", "/wizards/bloodstorm/workroom.c");
  add_exit("cs",  "/world/city/cs");

  short_desc = "T‰m‰ on testi huone.";
  long_desc =   
 "No n‰pytell‰‰s t‰h‰n nytten jotain. T‰‰l huonees vois v‰h‰n \n"+
 "opetella n‰it‰ uusia juttuja mitk‰ on mulle viel‰ hieman hakusessa\n"+
 "niinkuin v‰h‰n kaikki viel velhona olemisessa.\n";

  property = allocate(1);
  property[0] = "no_summon";
  set_light(3);
}




