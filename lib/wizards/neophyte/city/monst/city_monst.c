inherit "obj/monster";

int kohta;


reset(arg) {
  ::reset(arg);
  if(arg) return;
  
  call_out("kavele",20);
  set_name("Testimobsi");
  set_alias("testi");
  set_short("Wandering test-monster patrolling his predefined bugging route.");
  set_long("Look, its alive!\n");
  set_level(100);
  set_al(10);
  kohta = 0;
}

status kavele() {
	
	string *dirrikat;
	// Taman pitaa olla sellainen all-around rinkula eli alkupaikka sama kuin loppu.
	// Talla hetkella tama lahtee cs:lta, tekee rinkulan ja lopettaa sinne.
	dirrikat = ({
		"east",
		"east",
		"south",
		"east",
		"east",
		"east",
		"north",
		"north",
		"north",
		"west",
		"west",
		"west",
		"south",
		"south",
		"west",
		"west",
		"west",
		"south",
		"east",
		"west",
		"north",
		"east",
		});
	
	init_command(dirrikat[kohta]);
	say(this_object()->query_name()+" Juoksen onnellisena!\n");

	kohta++;
	if(kohta>=sizeof(dirrikat)) {
		kohta = 0;
		say("Nyt maa lopetin mun kierroksen ja lahden taas!\n");
	}

	call_out("kavele",20);

return 1;
}


