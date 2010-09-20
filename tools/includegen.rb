#!/usr/bin/env ruby
require 'pathname'
require 'fileutils'

# example howto call
# includegen.rb src include/lib/


dfiles = File.join(ARGV[0],"**", "*.{hpp,h}")
files = Dir.glob(dfiles)

source_dir = File.expand_path(ARGV[0])
puts source_dir

files.each{|file|
       
       file_orig = File.basename(file)
       
       header_dir = ARGV[1] + File.expand_path(File.dirname(file)).gsub(source_dir, "") + "/"
       header_file = File.basename(file, File.extname(file))
       
          
       path_to = Pathname.new(ARGV[0]).relative_path_from(Pathname.new(header_dir))
       
       
       header_complete = header_dir + header_file
       incl_path_complete = path_to.to_s() + "/" + file_orig
          
          
       # check if file exists   
       if File.exists?(header_complete) then
            puts "File: " + header_complete + " already exists"
            next 
       end
          
       FileUtils::mkdir_p(header_dir)
       
       # open file for write
       file   = File.open(header_complete, File::WRONLY|File::EXCL|File::CREAT) 
       file.syswrite("#include \"" + incl_path_complete + "\"")
       file.close

       puts "Write file: " + header_complete
          
}
