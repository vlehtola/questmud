string labeli;

short() {
	if(!labeli) 
	 return "A bottle of beer (labeled 'Koff')";
	 else
	 return "A bottle of beer (labeled '"+labeli+"')";
	}

long() {
  write("A bottle of beer, brought from another dimension\n");
  write("probably by Walla or Nalle.\n");
  }

get() { return 1; }

drop() { return 0; }

id(str) { return str == "beer"; }

init() {
  add_action("juo", "drink");
}

juo(str) {
  if(str != "beer" && str != "beer") { return; }
  write("AAAAh, that feels good.\n");
  this_player()->drink_soft(10000);
  destruct(this_object());
  return 1;
}

string init_beer()
{
 string *beerlist;
 beerlist =
        ({"Koff","Lapin Kulta","Karhu","Olvi","Karjala","Sandels","Nikolai",
        "Light Beer","Staropramen","Guinness","Koff Velvet","Murphy's",
        "Velkopopovic","Pripps","Budweiser","Legenda","Urho","Doppelbock",
        "Pilsner Urquell","Heineken","Carlsberg","Sol","Tuulik","Saaremaa","Fuller's",
        "Two Dogs","Kirin","Newcastle Brown Ale","Leffe","Stella Artois",
        "Hoegaarden","Kilkenny","Saku","Löwenbrau","Falcon" });
 labeli = beerlist[random(sizeof(beerlist))];
}
