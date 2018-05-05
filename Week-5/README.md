# The final project: Database

Write a C++ program that will serve as a database (non-persistent).

```
- Add event:			Add <date> <event>
- Delete event:			Del <date> <event>
- Delete events by date:	Del <date>
- Find events by date:		Find <date>
- Print all content:		Print
```

#### Add
* Required args: date event
* Don't store duplicates


#### Del
* Required args: date
* Optional args: event
* Output:
	* `Del <date> <event>	# Deleted successfully`
	* `Del <date> 		# Deleted <N> events`
	* `Del <date> 		# Event not found`

#### Find
* Required args: date
* Output:
	* events, sorted lexicographically, separated with the new line

#### Print
* Args: No
* Output:
	* YYYY-MM-DD event_string\n
	* 

