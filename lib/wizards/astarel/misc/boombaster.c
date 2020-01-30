// BoomBaster v1.0

mapping lyrics;
status playing;
int kohta,koko;
string *soitettava;
string *rfeelings;
string band,song;

void play_song(string *arr,status flag);

reset(arg) {
  if(arg) return;
playing = 0;

kohta = 0;
koko = 0;

rfeelings= ({ "BoomBaster echoes 'This is veeeery touching, right?'",
	      "The RadioDJ Astarel says 'This song is really touching.'",
	      "BoomBaster echoes 'Remember, You are listening the Astarel's Radio show at Radio QuestMUD'",
	      "You can hear weird mumbling from the BoomBaster, perhaps The RadioDJ Astarel is drinking booze.",
	      
	      });

lyrics = ([ 
	"rhcp": 
		(["californication": ({ 
					"Psychic spies from China",
					"Try to steal your mind's elation",
					"Little girls from Sweden",
					"Dream of silver screen quotations",
					"And if you want these kind of dreams",
					"It's Californication",
					"It's the edge of the world",
					"And all of western civilization",
					"The sun may rise in the East",
					"At least it settles in the final location",
					"It's understood that Hollywood",
					"sells Californication",
					"Pay your surgeon very well",
					"To break the spell of aging",
					"Celebrity skin is this your chin",
					"Or is that war your waging",
					"boombasterpause",
					"First born unicorn",
					"Hard core soft porn",
					"Dream of Californication",
					"Dream of Californication",
					"boombasterpause",
					"Marry me girl be my fairy to the world",
					"Be my very own constellation",
					"A teenage bride with a baby inside",
					"Getting high on information",
					"And buy me a star on the boulevard",
					"It's Californication",
					"Space may be the final frontier",
					"But it's made in a Hollywood basement",
					"Cobain can you hear the spheres",
					"Singing songs off station to station",
					"And Alderon's not far away",
					"It's Californication",
					"Born and raised by those who praise",
					"Control of population everybody's been there and",
					"I don't mean on vacation",
					"boombasterpause",
					"First born unicorn",
					"Hard core soft porn",
					"Dream of Californication",
					"Dream of Californication",
					"boombasterpause",
					"Destruction leads to a very rough road",
					"But it also breeds creation",
					"And earthquakes are to a girl's guitar",
					"They're just another good vibration",
					"And tidal waves couldn't save the world",
					"From Californication",
					"Pay your surgeon very well",
					"To break the spell of aging",
					"Sicker than the rest",
					"There is no test",
					"But this is what you're craving",
					"boombasterpause",
					"First born unicorn",
					"Hard core soft porn",
					"Dream of Californicatio",
					"Dream of Californication",}),
 			"otherside": ({
					"How long how long will I slide",
					"Separate my side I don't",
					"I don't believe it's bad",
					"Slit my throat",
					"It's all I ever",
					"I heard your voice through a photograph",
					"I thought it up it brought up the past",
					"Once you know you can never go back",
					"I've got to take it on the otherside",
					"Centuries are what it meant to me",
					"A cemetery where I marry the sea",
					"Stranger things could never change my mind",
					"I've got to take it on the otherside",
					"Take it on the otherside",
					"Take it on",
					"Take it on",
					"boombasterpause",
					"How long how long will I slide",
					"Separate my side I don't",
					"I don't believe it's bad",
					"Slit my throat",
					"It's all I ever",
					"boombasterpause",
					"Pour my life into a paper cup",
					"The ashtray's full and I'm spillin' my guts",
					"She wants to know am I still a slut",
					"I've got to take it on the otherside",
					"Scarlet starlet and she's in my bed",
					"A candidate for my soul mate bled",
					"Push the trigger and pull the thread",
					"I've got to take it on the otherside",
					"Take it on the otherside",
					"Take it on",
					"Take it on",
					"boombasterpause",
					"How long how long will I slide",
					"Separate my side I don't",
					"I don't believe it's bad",
					"Slit my throat",
					"It's all I ever",
					"boombasterpause",
					"Turn me on take me for a hard ride",
					"Burn me out leave me on the otherside",
					"I yell and tell it that",
					"It's not my friend",
					"I tear it down I tear it down",
					"And then it's born again",
					"boombasterpause",
					"How long how long will I slide",
					"Separate my side I don't",
					"I don't believe it's bad",
					"Slit my throat",
					"It's all I ever",
					"boombasterpause",
					"How long I don't believe it's bad",
					"Slit my throat",
					"It's all I ever",
					}),
 				]),
 		"metallica": ([ "one": ({
					"I Can't Remember Anything",
					"Can't Tell If this Is True or Dream",
					"Deep down Inside I Feel to Scream",
					"this Terrible Silence Stops Me",
					"Now That the War Is Through with Me",
					"I'm Waking up I Can Not See",
					"That There Is Not Much Left of Me",
					"Nothing Is Real but Pain Now",
					"boombasterpause",
					"Hold My Breath as I Wish for Death",
					"Oh Please God,wake Me",
					"boombasterpause",
					"Back in the Womb its Much Too Real",
					"in Pumps Life That I must Feel",
					"but Can't Look Forward to Reveal",
					"Look to the Time When I'll Live",
					"Fed Through the Tube That Sticks in Me",
					"Just like a Wartime Novelty",
					"Tied to Machines That Make Me Be",
					"Cut this Life off from Me",
					"boombasterpause",
					"Hold My Breath as I Wish for Death",
					"Oh Please God,wake Me",
					"boombasterpause",
					"Now the World Is Gone I'm Just One",
					"Oh God,help Me Hold My Breath as I Wish for Death",
					"Oh Please God Help Me",
					"boombasterpause",
					"Darkness",
					"boombasterpause",
					"Imprisoning Me",
					"All That I See",
					"Absolute Horror",
					"I Cannot Live",
					"I Cannot Die",
					"Trapped in Myself",
					"Body My Holding Cell",
					"boombasterpause",
					"Landmine",
					"boombasterpause",
					"Has Taken My Sight",
					"Taken My Speech",
					"Taken My Hearing",
					"Taken My Arms",
					"Taken My Legs",
					"Taken My Soul",
					"Left Me with Life in Hell",
				}),
			"nothing_else_matters": ({
					"So close no matter how far",
					"couldn't be much more from the heart",
					"forever trusting who we are",
					"and nothing else matters",
					"boombasterpause",
					"never opened myself this way",
					"life is ours, we live it our way",
					"all these words I don't just say",
					"and nothing else matters",
					"boombasterpause",
					"trust I seek and I find in you",
					"every day for us something new",
					"open mind for a different view",
					"and nothing else matters",
					"boombasterpause",
					"never cared for what they do",
					"never cared for what they know",
					"but I know",
					"boombasterpause",
					"so close no matter how far",
					"couldn't be much more from the heart",
					"forever trusting who we are",
					"and nothing else matters",
					"boombasterpause",
					"never cared for what they do",
					"never cared for what they know",
					"but I know",
					"boombasterpause",
					"never opened myself this way",
					"life is ours, we live it our way",
					"all these words I don't just say",
					"boombasterpause",
					"trust I seek and I find in you",
					"every day for us something new",
					"open mind for a different view",
					"and nothing else matters",
					"boombasterpause",
					"never cared for what they say",
					"never cared for games they play",
					"never cared for what they do",
					"never cared for what they know",
					"and I know",
					"boombasterpause",
					"so close no matter how far",
					"couldn't be much more from the heart",
					"forever trusting who we are",
					"no nothing else matters",
					}),
				]),

		]);

}

init() {

	add_action("boombaster_request","request");
	add_action("boombaster_list","list");
}

status boombaster_request(string str) {

mapping mapp;
	
	if(playing == 1) {
		write("The BoomBaster is already playing some song.\n");
		return 1;
	}
		
	if(!str) {
		write("request <band> <song>\n");
		return 1;
	}
	
	if(sscanf(str,"%s %s",band,song) != 2) {
		write("request <band> <song>\n");
		return 1;
	}
	
if(!lyrics[lower_case(band)]) {
	write("No such band in list.\n");
	return 1;
}

mapp = lyrics[lower_case(band)];

if(!mapp[lower_case(song)]) {
	write("No such song on list.\n");
	return 1;
}


soitettava = mapp[lower_case(song)];

tell_room(environment(this_object()),"BoomBaster echoes 'This is Astarel's hilarious show at Radio QuestMUD.'\n"+
				     "                  'Next song is "+capitalize(band)+" - "+capitalize(song)+"'\n"+
				     "			'Have a nice day'.\n\n"
);

call_out("play_songa",5);



return 1;
}

void play_songa() {
play_song(soitettava,1);
}


status boombaster_list() {


	
string *artist;
string *songs;
int i,b;

artist = m_indices(lyrics);

for(i=0;i<sizeof(artist);i++) {
	
	write(capitalize(artist[i])+"\n");
	
songs = m_indices(lyrics[artist[i]]);

for(b=0;b<sizeof(songs);b++) {
		write("\t - "+capitalize(songs[b])+"\n");
}
}
return 1;
}

void play_song(string *arr,status flag) {

	if(!arr)return;
	
if(flag == 1) {
	kohta = 0;
	koko = sizeof(arr);
	playing = 1;
}
if(arr[kohta] != "boombasterpause") {
if(kohta <= koko)tell_room(environment(this_object()),"BoomBaster booms out the music '"+arr[kohta]+"' \n");
}

else tell_room(environment(this_object()),rfeelings[random(sizeof(rfeelings))]+"\n");

kohta++;
if(kohta >= koko) {
	tell_room(environment(this_object()),"BoomBaster stopped playing the song.\n"+
					     "BoomBaster echoes 'And that was "+band+" - "+song+" \n");

	playing=0;
	return;
}

if(playing==1)call_out("play_songi",4);

}

void play_songi() {
	play_song(soitettava,0);
}



short() {
  return "A huge mobile-stereo system called 'BoomBaster'";
}

id(str) {
  return str == "boombaster";

}

long() {
  write("It has two huge speakers attached on it sides.\n");
}

get() {
	return 0;
}

query_weight() {
  return 1;
}

