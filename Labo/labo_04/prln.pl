#!/usr/bin/perl
use v5.26;
use warnings;

my @inpts;
foreach(@ARGV){
    push(@inpts,$_);
}

foreach(@inpts){
    if($_ eq '-cmk'){
        &cmk;
        }
    if($_ eq '-NewSv'){
        if($inpts[$_+1] gt 0){
            
        }
    }
}

sub NewSv{

}
sub cmk{

my $cmake;
if(! open $cmake,'>',"CMakeLists.txt"){
    die "Can't write 'CMakeLists.txt': $!";
}
my %cmk_data=(
    'project' => 'project(cmake_generated)',
    'set_flags' => 'add_compile_options(-Wall -Wextra -Werror -g)'
    'min_V' => 'cmake_minimum_required(VERSION 3.10)',
    'set_inc' =>'set(INCROOT ${CMAKE_CURRENT_SOURCE_DIR}/)',
    'set_src' =>'set(SRCROOT ${CMAKE_CURRENT_SOURCE_DIR}/)',
    'set_dir' =>'set(DIRROOT ${CMAKE_CURRENT_SOURCE_DIR}/)',
    'set_rt_out' =>'set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})',
    'set_out' => 'set(OUT_NAME main)',
    'set_libs' =>'set(LIBS )',
    'set_files_h' =>"set(FILES_HEADER\n)",
    'set_files_src' =>"set(FILES_SRC\n)",
    'set_files' =>"set(FILES_DIR\n)",
    'inc_dirs' =>'include_directories(${FILES_DIR})',
    'add_ex' => 'add_executable(${OUT_NAME} ${FILES_SRC})',
    'link_libs' => 'target_link_libraries(${OUT_NAME} ${LIBS})'
);
my @key=qw (project
        min_V 
        set_inc 
        set_src 
        set_dir
        set_rt_out 
        set_out 
        set_flags 
        set_libs 
        set_files_h
        set_files_src
        set_files
        inc_dirs
        add_ex
        link_libs
);
my $h_rot="\$\{INCROOT\}\/";
my @dirHeaders=`find . -name \'*.h\' -o -name \'*.hpp\'`;

foreach my $dirH(@dirHeaders){
    $dirH=~s/\A\.\///;
    $dirH=~s/\n//;
    $cmk_data{set_files_h} =~s/(set\(FILES_HEADER)/${^MATCH}\n\t$h_rot$dirH/p;
}
foreach(@dirHeaders){
    
    my $lstSlash=rindex($_,"/");
    my $subtr=substr($_,0,$lstSlash+1);
    $_=$subtr;
}

my $d_rot='${DIRROOT}/';
my $oldH=0;
#my $newDirH;
@dirHeaders=sort(@dirHeaders);

foreach my $dirF(@dirHeaders){
    if($oldH eq $dirF){
        ;
    }else{
        if($cmk_data{set_files}=~s/(set\(FILES_DIR)/${^MATCH}\n\t$d_rot$dirF/p){
        #say $dirF;}
    }
    $oldH=$dirF;
}

my @dirSrc=`find . -name \'*.c\' -o -name \'*.cpp\'`;
my $c_rot="\$\{SRCROOT\}\/";
foreach my $file(@dirSrc){
    $file =~s/\A\.\///;
    $file =~s/\n//;
    if($file=~/\.c(pp)?\Z/){
        if($cmk_data{set_files_src}=~s/(set\(FILES_SRC)/${^MATCH}\n\t$c_rot$file/p){
            ;
        }
    }
}

foreach my $kis(@key){
    printf $cmake ("%s\n",$cmk_data{$kis});
}
}

