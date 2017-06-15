package com.rxhui.rwhdf5

import java.io.File

import scala.io.Source

/**
  * Created by dell on 2017/5/18.
  */
object ReadAllFile {
  private val readDir = "D:/futurePrice"
  private val csvFile = "D:/futurePrice/future_price20170329.txt"
  private val hdf5File = "D:/futurePrice/future_price20170329.hdf5"
  
  /**
  下面是一段递归获取目录名称的代码：
  def subdirs(dir: File): Iterator[File] = {
    val children = dir.listFiles.filter(_.isDirectory)
    children.toIterator ++ children.toIterator.flatMap(subdirs _)
  }
  稍加改动后变成获取文件名的代码，如下：
   def subdirs2(dir: File): Iterator[File] = { 
    val d = dir.listFiles.filter(_.isDirectory) 
    val f = dir.listFiles.filter(_.isFile).toIterator 
    f ++ d.toIterator.flatMap(subdirs2 _) 
  }
  最后再稍微改改，即可获得指定目录下所有的文件名和目录名：
  def subdirs3(dir: File): Iterator[File] = { 
    val d = dir.listFiles.filter(_.isDirectory) 
    val f = dir.listFiles.toIterator 
    f ++ d.toIterator.flatMap(subdirs3 _) 
  } 
  */

  def subdirs(dir: File): Iterator[File] = {
    val d = dir.listFiles.filter(_.isDirectory)
    val f = dir.listFiles.filter(_.isFile).toIterator
    f ++ d.toIterator.flatMap(subdirs)
  }

  def ReadCsvFile(filename: String): Unit = {
    val source = Source.fromFile(filename, "UTF-8")
    val lineIterator = source.getLines()

    for (line <- lineIterator) {

      val tokens = line.mkString.split("\t")
//      println(tokens.length)

      for (item <- tokens) {
        print(item + "    ")
      }
      println()

    }
  }

  def main(args: Array[String]) {
    val dirin = new File(readDir)
    for (file <- subdirs(dirin)) {
      println(file.getName)
    }

    ReadCsvFile(csvFile)
  }
}
