const std = @import("std");
const day_1 = @import("day_1.zig");

pub fn main(init: std.process.Init) !void {
    try day_1.day1(init.io, init.gpa);
}
