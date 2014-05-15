
asciiList = File.open('ascii')
outfile = File.open("asciiout.txt", 'w')

=begin

byte a_base[] PROGMEM = {
  000, //0, 0, 0, 0, 0, 0, 
  000, //0, 0, 0, 0, 0, 0, 
  034, //0, 1, 1, 1, 0, 0, 
  002, //0, 0, 0, 0, 1, 0, 
  036, //0, 1, 1, 1, 1, 0, 
  042, //1, 0, 0, 0, 1, 0, 
  036, //0, 1, 1, 1, 1, 0, 
  000  //0, 0, 0, 0, 0, 0
}

=end


charOffset = 0

asciiList.each_line do |line|
	data =line.gsub(/\s+/m, ' ').strip.split(" ")
	asciiIdx=data[0]
	character=data[1]
	length=(data[2].to_i) * 2
	thisOut = "\nbyte " + character + "_base[] PROGMEM = {\n"

	asciiLineFile =File.open('asciiin.txt')
	asciiLineFile.each_line do |arrayLine|
		asciiLine = arrayLine[charOffset, length] + "\n"
		thisOut+= asciiLine
	end
	asciiLineFile.close

	thisOut += "}\n"

	outfile.write(thisOut)
	charOffset += length
end

asciiList.close