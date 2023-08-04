
#!bin/bash
Records="Employees.txt"

print_menu()
{
	echo "1. Add employee"
	echo "2. Delete employee"
	echo "3. Search employee"
	echo "4. Sort file"
	echo "5. List file"
	echo "Exit"

}
add_record()
{
	echo "Enter name"
	read name
	echo "Enter Eid"
	read Enum
	echo "Enter Telephone number"
	read Tnum
	
	echo "${name},${Enum},${Tnum}">>"$Records"

	echo "                                                    ----------Records  added   Successfully------------"

}
delete_record()
{	
	echo "Enter Emp Number to delete"
	read Enum

	grep -v "^.*,$Enum,.*$" "$Records"> temp.txt 
	mv temp.txt "$Records"
	echo "                                  ------------------Records deleted Successfully----------------------"
}
search_record()
{
	echo "Enter Name to Search."
	read search_key

	grep -i "$search_key"  "$Records"
}
sort_records()
{
	sort "$Records" -o "$Records"

	echo "------------------Records Sorted Successfully--------------"
}
list_records()
{
	cat "$Records"
}
while true; do
	print_menu

	echo "Enter your choice:"
	read choice

	case $choice in
		1) add_record ;;
		2) delete_record ;;
		3) search_record ;;
		4) sort_records ;;
		5) list_records ;;
		6) echo "Exiting....."; break ;;
		*) echo "Invalid entry" ;;
	esac
done
			
	



