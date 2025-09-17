---
layout: page
title: Ruby
---

# {{page.title}}
<figure>
<img width="200" height="200" src="/assets/ruby.webp">
<figcaption><i>AI Generated Image</i></figcaption>
</figure>

## Resources
* [Official Documentation](https://www.ruby-lang.org/en/documentation/)
* [Online Ruby Interpreter](https://try.ruby-lang.org/)
## The Basics Of Ruby
## Strings
Operators:
```ruby
# Append
greeting = "hello"
greetting << ' '
greeting << 'world'
```
Methods:
```ruby
# convert string to int
'1'.to_i
# Convert int to str
1.to_s
# ruby can extract ints from string.
# the example returns: 6
'6 blue cakes'.to_i
# Careful here as it only works if the first char is int
# Other methods
x = 'hello'
x.reverse
x.capitalize
x.upcase
x.downcase
x.length
x.split(',') # turns string into array
# because every ruby method returns an obj we can combine multiple methods
x.reverse.capitalize.upcase.length
```
How to do interpolation? 
```ruby
msg = "I like potatoes"
puts "I said: #{msg}"
```
Note: Interpolation can be done with calculations too:
```ruby
puts "1 + 1 = #{1+1}"
```
Single quoted strings do not allow interpolation
### Arrays
* Arrays can contain a mix of types
* nil is returned when there is no value in the given index
* You can add indexes larger than the current size and the positions between will be filled with `nil`
* You can use append notation to add to the end of an array (`array << 'last item'`)
```ruby
# Basic example:
fruit = [] # empty array
fruit = ['apple', 'banana', 'pear']
puts fruit[0]
fruit[0] = 'berry'
puts fruit
```
* Supported array methods:
	* length/size
	* reverse
	* shuffle
	* uniq
	* compact (removes empty positions)
	* flatten (if the array contains an object, it takes them out and makes them part of the array)
	* include?(arg) 
		* This is a query where we are asking: Does the array contain x argument as an element?
		* This returns a boolean 
	* delete_at(index)
	* delete(value)
	* join
		* It can also take a delimiter: `x.join(',')`
	* first
	* last
	* push(value)
		* adds `value` to the end
	* pop
		* removes last item
	* shift
		* takes the first item
	* unshift(value)
		* adds `value` to the beginning

* Some methods use the `!` which updates the array after executing. For example:f
```ruby
fruit = ['apple', 'banana', 'pear']
fruit.reverse!
puts fruit
# now fruit is reversed and saved as reversed
```

### Hashes
* Unordered object index collection
* Example hash:
```ruby
player = {
	'name' => 'john',
	'age' => 22,
	'level' => 50,
	'race' => 'elf',
	'class' => 'mage'
}
puts player['name;']
puts player['class']
puts player['level']
```

### Symbols
* Similar to strings*
* symbols begin with a `:`
* Not delimited by quotes
* **rules:** lowercase, underscore, no spaces
* symbols and hashes are not interchangeable
* a string can be converted to a symbol: `person['first_name'].to_sym`
* key is always a symbol
* cannot use `ints` as keys (`:15` is not valid)
#### Example:
```ruby
person = {
	:first_name => 'john',
	:last_name => 'smith'
}
puts person[:last_name]
# Short hand
person2 = {
	first_name: 'anna',
	last_name: 'smith' 
}

puts person2
```

#### Why use symbols?
* **Immutability**: Symbols are not editable, so you don't have to worry about the key being changed.
- **Memory Efficiency**: Symbols are created once and reused, which uses less memory compared to strings, which create a new object each time.

### Boolean

| Meaning                  | symbol |
| ------------------------ | ------ |
| Equals                   | `==`   |
| Less than                | `<`    |
| Greater than             | `>`    |
| Less than or equal to    | `<=`   |
| Greater than or equal to | `>=`   |
| Not                      | `!`    |
| Not equal                | `!=`   |
| And                      | `&&`   |
Something cool ruby does. 
```ruby
[1,2,3,4,5,6].include?(2)
# This is a boolean test. It will return true if the value 2 is included in the array. False otherwise
users=['john','peter','mario','clark']
users.include?('mario')
players = {
	'p1' => 'john',
	'p2' => 'mario',
	'p3' => 'clark',
	'p3' => 'demian'
}
players.has_key('p4')?
players.has_value('pete')?
```

### Ranges
* inclusive range: `1..5`
* Exclusive range: `1...5`

### Constants
* Ruby allows you to change the value of a constant
* any name that starts with a capital letter is a constant
* 

### Nil
Basic class.
Can be returned when searching for an object but nothing found
```ruby
# Testing for nil
product == nil
product.nil?
!product
```


## Control Structures
### Conditions
Basic example. There is nothing really unique worth anotating
```ruby
#!/usr/bin/ruby
player = {
	'hp' => 100,
	'mp' => 100,
	'st' => 100
}

if player['hp'] == 0
	puts "Player died. Game over"
elsif player['hp'] < 50
	puts "Plater hp is less than 50%"
else
	puts "Player is not dead yet and is in good health. Current HP: #{player['hp']}"
end

if player['name'].nil?
    puts "player has no name"
end
```

#### Unless
evaluates false. Formula:
```ruby
unless boolean
# code here
end
# unless is the same as:
if !boolean
# code here
end
```

**Example:**

```ruby
#!/usr/bin/ruby

cart = ['apple', 'banana', 'potato', 'onion', 'watermelon', 'melon']
#cart = []
unless cart.empty?
  puts "the cart contains #{cart.length} items"
else
  puts "the cart is empty"
end

```

#### Case statements

General formula:
```ruby
case 
when boolean
# code here
when boolean
# code here
else
# code here
end
```
**Example:**
```ruby
#!/usr/bin/ruby
puts "enter number of players: "
count = gets.chomp.to_i 
case
when count == 0
  puts "No player found"
when count == 1
  puts "1 player found"
when count == 2
  puts "2 players found"
when (3..8).include?(count)
  puts "more than 3 but less or exactly 8 players found"
else
  puts "More than 8 players found"
end
```
#### Case with comparisons
General formula:
```ruby
case test_value
when value
# code here
when value 
# code here
else
# code here
end
```

Example:
```ruby
#!/usr/bin/ruby
puts "enter number of players: "
count = gets.chomp.to_i 
case count
when 0
  puts "No player found"
when 1
  puts "1 player found"
when 2
  puts "2 players found"
when 3..8
  puts "more than 3 but less or exactly 8 players found"
else
  puts "More than 8 players found"
end
```

#### Ternary Operator
* General formula: `boolean ? true : false`
* example: `puts count == 1 ? "Person" : "People"`
* This is short for:
```ruby
if count == 1
	puts "Person"
else
	puts "People"
end
```
#### Or Operator
* General Formula: `x = y || z`
	* X gets set to the value Y if Y has a value otherwise x gets set to the value of z
* Example: `name = user_name || new_name`
* This is short for:
```ruby
if name == user_name
	name = user_name
else
	name = new_name
end
 ```
#### Or equals  operator
* General formula: `x ||= y`
* Example: `name ||= user_name`
* This is useful for setting default values
* This is short for:
```ruby
unless x
 x = y
end
```

#### Statement modifies
* `if` and `unless`  can be used as statement modifiers
* Examples:
```ruby
#!/usr/bin/ruby
fav_food = ['pizza', 'burger', 'rice']
puts "Love potato" if fav_food.include?("potato")
MAX_MAGIC = 100
player1 = {
	'name' => "jdoe",
	'magic' => 50,
	'strength' => 30,
	'level' => 2,
	'health' => 100
}
puts "Player Stats"
puts "Name = #{player1['name']}"
puts "Magic = #{player1['magic']}"
player1['magic'] += 10 unless player1['magic'] >= MAX_MAGIC
puts player1

```

#### Loops
* General formula
```ruby
loop do
# code here
end
```

* Loop control methods:
	* `break`: terminates the loop
	* `next`: jumps to the next loop
	* `redo`: redo the current loop (jumps back to the beginning)
	* `retry:` starts the whole loop over
* Example: 
```ruby
i=5
loop do
	break if 1 <= 0
	puts "Countdown: #{i}"
	i -= 1
end
puts "Blast off!"
```
#### while, until loops
- General Formula:
```ruby
while boolean
# code here
end

until boolean
# code here
end
```

* Example
```ruby
#!/usr/bin/ruby
i = 5
until i <= 0
	puts "Countdown #{i}"
	i -= 1
end
puts "Blast off"

c = 5
while c > 0
	puts "Countdown #{c}"
	c -= 1
end
puts "Blast off"	
```

#### Iterators
* `do` and `end` key words are used for multi line iteration operations
* `{}` are used for single line iterations.
* Examples:
```ruby
# multiline
5.times do
	puts "hello world"
end
# single line
5.times { puts "hello world" }
```

* `each`: This is a fundamental iterator used to visit each element in a collection.
```ruby
array = [1, 2, 3]
array.each do |element|
    puts element * 2
end
```
- `map` (or `collect`): This iterator transforms each element in a collection and returns a new array containing the results of the transformation.
```ruby
numbers = [1, 2, 3]  
doubled_numbers = numbers.map { |n| n * 2 }  
puts doubled_numbers.inspect 
# Output: [2, 4, 6]
```
- `select` (or `filter`): This iterator filters elements based on a condition and returns a new array containing only the elements for which the block evaluates to true.
```ruby
numbers = [1, 2, 3, 4, 5]
even_numbers = numbers.select { |n| n.even? }
puts even_numbers.inspect # Output: [2, 4]
```
- `upto` and `downto`: These iterators iterate from a starting value up to or down to an ending value.
```ruby
1.upto(3) { |i| puts i } # Output: 1, 2, 3
3.downto(1) { |i| puts i } # Output: 3, 2, 1
```

### Exit and abort
```ruby
# Abort example
1.upto(10) do |n|
	if n== 5
		# exit
		abort("exiting on 5")
	end
	puts n
end

1.upto(10) do |n|
	if n== 5
		# exit
		abort("exiting on 5")
	end
	puts n
end

```

### Dates and time
#### Time
* Uses epoch
* How to use time class:
```ruby
now = Time.now
# => 2025-08-06 12:10:20.836320413 -0400
now.class
# Time
now.to_i
# returns epoch as int
# 1754496620
Time.at(1754496620)
# 2025-08-06 12:10:20 -0400
# ---
# Create a new timestamp
Time.new(year, month, day, hour, min, sec, utc_offset)
# Examples:
Time.new(2027, 10, 31, 2, 15, 0, "+02:00")
Time.new(2025, 10, 31)
```

##### Time Addition
```ruby
tomorrow = Time.now + (60*60*24)
next_week = Time.now + (60*60*24*7)
next_year = Time.new + (60*60*24*365)
yesterday = Time.new - (60*60*24)
last_week = Time.new - (60*60*24*7)
last_year = Time.new - (60*60*24*365)
```
##### Time instance methods
```ruby
# year, month, day, hour, min, sec, nsec
yday # day of the year
wday # week day ( sun = 0)
sunday? # returns true if today is sunday
strftime # returns string representation of timestamp for formatting
zone # returns timezone
utc? # returns true if timezone is utc
gmt_offset # returns gmt timezone offset
getutc # returns time in utc

```
#### Date
* similar to time
* does not include h:m:s
* better supports for historical dates (changes in different calendars)
* Not loaded by default need: `require date`
* `DateTime` is deprecated
* Examples:
```ruby
Date.today
# => #<Date: 2025-08-06 ((2460894j,0s,0n),+0s,2299161j)>
today = Date.today
today.ctime
# => "Wed Aug  6 00:00:00 2025"
bday = Date.new(2014,10,1)
cakeday = Date.parse('Jul, 13, 1976')
puts cakeday.ctime
# Tue Jul 13 00:00:00 1976
Date.today.to_time
# => 2025-08-06 00:00:00 -0400
Time.now.to_date
# => #<Date: 2025-08-06 ((2460894j,0s,0n),+0s,2299161j)>
```
##### Data Instance methods
```ruby
year, month, day
yday
wday
sunday?
strftime
leap?
cweek, cwday # calendar week/day
prev_day/month/year
next_day/month/year
gregorian?
```

### Enumerables and code blocks
#### Enumerable
#### Code blocks

#### Find methods

#### Map method

#### Inject methods

#### Sort  methods

#### Merge methods

### Custom methods
### Classes











<hr>
## Ruby Graphic Applications

## RAILS

### Notes on my diabetes readings CRUD Web app

* **What Does config/routes.rb Do?**
	* This file defines how **URLs** (routes) map to **controller actions** in your Rails app. It tells Rails:
		* Which controller to use for a given URL
		* Which HTTP method (GET, POST, DELETE, etc.) is allowed
		* What the URL should look like (`/readings`, `/new`, etc.)
		* What view (HTML, JSON, etc.) to render
		* *In short: this file is the **central routing table** for your app.*

* **Code snippet:**
```ruby
Rails.application.routes.draw do
	root "readings#index"
	resources :readings, only: [:index, :new, :create, :destroy]
end
```

* **Explanation**

| Route           | HTTP Verb | Controller#Action  | Purpose             |
| --------------- | --------- | ------------------ | ------------------- |
| `/`             | GET       | `readings#index`   | Home page           |
| `/readings`     | GET       | `readings#index`   | View all readings   |
| `/readings/new` | GET       | `readings#new`     | Form to add reading |
| `/readings`     | POST      | `readings#create`  | Save reading to DB  |
| `/readings/:id` | DELETE    | `readings#destroy` | Delete reading      |

#### Simple Diagram: Rails Routes → Controller Actions

```ruby
   ┌──────────────────────────────┐
   │  HTTP Request (e.g., GET)    │
   └────────────┬─────────────────┘
                ↓
   ┌──────────────────────────────┐
   │ config/routes.rb             │
   │ e.g. resources :readings     │
   └────────────┬─────────────────┘
                ↓
   ┌──────────────────────────────┐
   │  ReadingsController          │
   │  with actions like:          │
   │  - index                     │
   │  - new                       │
   │  - create                    │
   │  - destroy                   │
   └────────────┬─────────────────┘
                ↓
   ┌──────────────────────────────┐
   │  View (e.g., index.html.erb) │
   └──────────────────────────────┘
# Every route defined in `routes.rb` maps to a controller action, which then typically renders a view.
```

#### RESTful Routes Cheat Sheet

When you write: `resources :readings` You get all 7 standard RESTful routes:

|HTTP Verb|Path|Controller#Action|Purpose|
|---|---|---|---|
|GET|`/readings`|`index`|Show all readings|
|GET|`/readings/new`|`new`|Show form to create one|
|POST|`/readings`|`create`|Save new reading|
|GET|`/readings/:id`|`show`|Show one reading (optional)|
|GET|`/readings/:id/edit`|`edit`|Show form to edit reading|
|PATCH/PUT|`/readings/:id`|`update`|Update existing reading|
|DELETE|`/readings/:id`|`destroy`|Delete reading|
#### Rails Route Helper Methods

|Helper|What it does|
|---|---|
|`readings_path`|`/readings`|
|`new_reading_path`|`/readings/new`|
|`reading_path(@reading)`|`/readings/:id` (for show/delete)|

These are used in views and controllers, e.g.:

```erb
<%= form_with model: @reading, url: readings_path, method: :post %>
<%= link_to "Delete", reading_path(reading), method: :delete %>
```

Notes on some specific files:
* `app/views/readings/new.html.erb`
	* This file is the **HTML view** (with embedded Ruby) for the **`new` action** in your `ReadingsController`.
	* When you visit `/readings/new` in your browser, Rails:
		* Goes to the `ReadingsController` → `new` action.
		* That action renders this view: `new.html.erb`.
		* The view contains a form that you fill in and submit to create a new reading.
		* Uses `<%= form_with model: @reading %>` to build the form.
		* Points to `readings#create` when submitted (via POST).
		* Fields map to the model (`blood_sugar`) and auto-populate validation errors if present.
* `app/controllers/readings_controller.rb`
	* This file contains the **controller logic** for all actions related to the `Reading` model.
	* It **controls the flow** of your app: receiving requests, talking to the model, and rendering views.
	* The controller is the middleman between:
		* The **browser** (incoming requests)
		* The **model** (your database)
		* The **view** (what the user sees)
```ruby
# - Sets up a new (empty) @reading object for the form.
# - Required for form_with model: @reading to work correctly.
def new
  @reading = Reading.new
end

#-----
# Receives the POSTed form data.
# Validates and saves it to the database.  
# Redirects to the homepage or re-renders the form if invalid.
def create
  @reading = Reading.new(reading_params)
  if @reading.save
    redirect_to root_path, notice: "Reading saved!"
  else
    render :new
  end
end
```