get_weapon_size(int i) {
	switch(i) {
		case 0..16: return "tiny";
		case 17..32: return "small";
		case 33..49: return "average";
		case 50..65: return "large";
		case 66..75: return "very large";
		case 76..85: return "huge";
		case 86..100: return "gigantic";
	}
	return "tiny";
}