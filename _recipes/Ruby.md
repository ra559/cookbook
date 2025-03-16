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


## Ruby Graphic Applications

## RAILS

## Ruby 2D


### Creating Snake
* How to draw the snake to the screen:
```ruby
#!/usr/bin/ruby

require 'ruby2d'

set background: 'navy'

GRID_SIZE = 20

class Snake
  def initialize
    @positions = [[2,0],[2,1],[2,2],[2,3]]    
  end
  def draw
    @positions.each do | position |
      Square.new(x:position[0] * GRID_SIZE, y:position[1]*GRID_SIZE,  size: GRID_SIZE -1, color: 'white')
    end
  end
end

snake = Snake.new
snake.draw
show

```
