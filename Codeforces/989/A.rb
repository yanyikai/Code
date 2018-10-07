puts gets.codepoints.each_cons(3).any?{|x,y,z|x*y*z==287430}?'Yes':'No'
