string *room = ({
"/world/city/cs",
"/world/city/gold3",
"/world/city/gold2",
"/world/city/gold1",
"/world/city/gold5",
"/world/city/gold6",
"/world/city/gold7",
"/world/city/gold8",
"/world/city/wood2",
"/world/city/wood3",
"/world/city/wood4",
"/world/city/wood5",
"/world/city/wood6",
"/world/city/silver1",
"/world/city/silver2",
"/world/city/silver3",
"/world/city/silver4",
"/world/city/silver5",
"/world/city/silver6",
"/world/city/silver7",
"/world/city/emerald1",
"/world/city/diamond2",
"/world/city/diamond3",
"/world/city/diamond4",
"/world/city/diamond6",
"/world/city/diamond7",
"/world/city/diamond1",
});

string query_rooms(int arg) { return room[arg]; }
query_room_size() { return sizeof(room); }
query_room() { return room; }
