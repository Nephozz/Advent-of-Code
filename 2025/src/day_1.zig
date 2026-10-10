const std = @import("std");

pub fn day1(io: std.Io, gpa: std.mem.Allocator) !void {
    const input = try std.Io.Dir.cwd().readFileAlloc(io, "inputs/day_1.txt", gpa, .limited(1 << 20));
    defer gpa.free(input);

    var position: i32 = 50;
    var zero_count: i32 = 0;

    var lines = std.mem.splitScalar(u8, input, '\n');
    while (lines.next()) |line| {
        const content = std.mem.trimEnd(u8, line, "\r");
        if (content.len == 0) continue;

        const amount = try std.fmt.parseInt(i32, content[1..], 10);
        position += switch (content[0]) {
            'L' => -amount,
            'R' => amount,
            else => return error.InvalidInput,
        };
        position = @mod(position, 100);
        if (position == 0) zero_count += 1;
    }

    std.debug.print("{d}\n", .{zero_count});
}
