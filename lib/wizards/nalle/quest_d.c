/* return 0, if not valid. >0, if valid. given value is the reward in quest points */
/* value between 1-10? */

/* kaikki questit on reinc proofeja */
int validate_quest(string quest, int reinc_proof) {
  switch(quest) {
/* #### ADD QUESTS BELOW THIS LINE #### */

case "Bury Justin's heart in his wife's grave": return 7;
// /wizards/veron/areat/cotd/ceme1

case "Finding Terran's son": return 2;
/* /wizards/ahma/ice/mob/dwarf01.c */
case "Performing the dirty work for Serak": return 1;
/* /wizards/ahma/ice/mob/dwarf02.c */
case "Helping out the neighbors": return 3;
/* /wizards/ahma/ice/mob/dwarf05.c */

case "Devouring the carnivorous plants": return 7;
/* /wizards/ahma/orc/mob/carnplant04. */
case "Discover the pond's secret": return 4;
/* /wizards/ahma/orc/forest/for11.c */
case "Reviving the ancient elemental": return 9;
/* /wizards/ahma/orc/forest/sub10.c */

case "Find the secret exit in the Mansion": return 2;
/* /wizards/veron/areat/golem room16 */

/* /wizards/gynter/element/gateway.c - Gynter's elementals */

case "Destroy the entrance to the fire plane": return 1;
case "Destroy the pillar to the air realm": return 1;
case "Destroy the gateway to the earth plane": return 1;
case "Destroy the entrance to the water plane": return 1;
case "Release the great spirit element": return 3;
case "Give vorpal blade to the lord of Air": return 4;
case "Give pouch to the stone elemental": return 4;
case "Return the key to the Fire Demon": return 4;
case "Return the icecube to the great white shark": return 4;

case "Return guard his sparkling sword": return 10;
/* /w/ahma/castle/rooms/area08 */
case "The death prevails": return 10;
/* /w/ahma/castle/rooms/area52 */
case "Discover markings": return 2;
/* /wizards/aarrgh/nyxi/ruin2.c */
case "Wake the mystical skeleton": return 2;
/* /w/a/n/mist2.c */
case "Open the flaming portal": return 6;
/*  /w/a/n/down1.c */
case "help woman with the mouse problem" : return 5;
/* (wizards/neophyte/farm/house.c") */
case "Bring man's watch back" : return 3;
/* (wizards/neophyte/forest/monst/man) */
case "Bring sheephide to goblin" : return 2;
/* (wizards/neophyte/city/monst/king) */
case "Find wolfrider den" : return 1;
/* (wizards/duncan/island/cave) */
case "Lure the Enchantress" : return 10;
/* (wizards/irmeli/valley/object/head) */
case "Bring the heart to the Knight" : return 10;
/* (wizards/irmeli/valley/monsters/knight) */
case "Find the ancient crab": return 2;
/* (wizards/torspo/areat/ogre/cave) */
case "Find the secret hideout in the Church": return 3;
/* (guilds/channels/r17) */
case "Return painting to the hobbit gardener": return 3;
/* (wizards/bulut/forl/monsters/gardener) */
case "Secret guild of the Acrobats": return 2;
/* (guilds/fighter/acrocitizen) */
case "Return the Holy Cross to the priest": return 6;
/* (wizards/grathlek/area1/monsies/mopriest) */
case "Open curtains in paladin training area": return 1;
/* (wizards/grathlek/area1/eroom12) */
case "Return the key to the Fire Demon": return 5;
/* (wizards/gynter/element/gateway) */
case "Release the great spirit element": return 10;
/* (wizards/gynter/element/gateway) */
case "Cross the river in the forest": return 1;
/* (wizards/irmeli/bwp/room8) */
case "Lure the witch out from the bushes": return 8;
/* (wizards/irmeli/bwp/eq/cloak) */
case "Find the secret hobbit gallery": return 3;
/* (wizards/irmeli/area2/ruum28) tuned. //Celtron */
case "Slay Darvox": return 15;
/* (wizards/nalle/area/monsters/mayor) */
case "Enter the magic mirror": return 3;
/* (wizards/nalle/area/darvroome) */
case "Help the wounded man": return 15;
/* (wizards/nalle/jerusalem/eq/varjo) */
case "Rescue the little kitten": return 8;
/* (wizards/nalle/jerusalem/monsters/towlady) */
case "Give Zephaniah a flask of Holy Water": return 4;
/* (wizards/nalle/jerusalem/monsters/zephaniah) */
case "Release a lady in David's Tower": return 7;
/* (wizards/nalle/jerusalem/dav2h) */
case "Return Layla's ring to the old man": return 5;
/* (wizards/shadow/Wolf/monsters/oldman) */
case "Bring the head of the seamonster to the Lizard King": return 12;
/* (wizards/siki/lizard/monsters/king) */
case "Dive into the cold water": return 2;
/* (wizards/siki/lizard/dock2) */
case "Help alchemist with his mission": return 10;
/* (wizards/walla/area/monsters/alchemist) */
case "Bring wolf head to Lalli": return 2;
/* (wizards/torspo/areat/gnomes/monsters/lalli) */
case "Slay Leb-Kamar": return 15;
/* (wizards/walla/jericho/mobs/leb.c) */
case "Escort child to safety": return 5;
/* wizards/siki/forest/room22.c */
case "Find the secret chamber of warlocks": return 1;
/* guilds/warlock/cathedral/room8 */

/**** Special questpoint awards *****/
case "Bug report (worth 4)": return 4;
/* (A substantial, important bug report) */
case "Feed Monkey": return 8;
/* Feed the monkey - An event worth questpoints! */

  }
 return 0;
}
