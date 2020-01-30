inherit "obj/monster";
reset(arg) {
   ::reset(arg);
if(arg) return;
set_name("king");
set_level(60);
set_race("human");
set_alias("wolf king");
set_short("the wolf king clad in wolf furs sits on a throne here");
set_long("A tall man clad in wolf furs sits here on a throne. He is wearing a crown\n"+
	 "and many rings. There is a strong aura emitting rom him. He has a long beard\n"+
	 "and deep eyes. His hair is long and brown, the color of wolf fur. He holds\n"+
	 "a huge hammer on his hand and a big book in the other. He has a large \n"+
	 "necklace with diamons embedded in it around his neck. His face is covered\n"+ 
	 "with many scars and he keeps looking around him all the time.\n");
}
